/***************************************************************************//**
*  \file       hello_world.c
*
*  \details    Simple hello world driver
*
*  \author     EmbeTronicX
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/moduleparam.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/err.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/proc_fs.h>


#define LINUX_KERNEL_VERSION  612


#if 0
// Code for passing parameters

// int valueETX, arr_valueETX[4];
// char *nameETX;
// int cb_valueETX = 0;
// module_param(valueETX, int, S_IRUSR|S_IWUSR);                      //integer value
// module_param(nameETX, charp, S_IRUSR|S_IWUSR);                     //String
// module_param_array(arr_valueETX, int, NULL, S_IRUSR|S_IWUSR);      //Array of integers
//
// /*----------------------Module_param_cb()--------------------------------*/
// static int notify_param(const char *val, const struct kernel_param *kp)
// {
//         int res = param_set_int(val, kp); // Use helper for write variable
//         if(res==0) {
//                 printk(KERN_INFO "Call back function called...\n");
//                 printk(KERN_INFO "New value of cb_valueETX = %d\n", cb_valueETX);
//                 return 0;
//         }
//         return -1;
// }
//
// const struct kernel_param_ops my_param_ops = 
// {
//         .set = &notify_param, // Use our setter ...
//         .get = &param_get_int, // .. and standard getter
// };
//
// module_param_cb(cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUGO|S_IWUSR );
// /*-------------------------------------------------------------------------*/
#endif

#define mem_size        1024           //Memory Size

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;
uint8_t *kernel_buffer;
int32_t value = 0;
static struct proc_dir_entry *parent;
char etx_array[20]="try_proc_array\n";
static int len = 1;




/*
** Function Prototypes
*/
static int      __init hello_world_init(void);
static void     __exit hello_world_exit(void);
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long     etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg);


/***************** Procfs Functions *******************/
static int      open_proc(struct inode *inode, struct file *file);
static int      release_proc(struct inode *inode, struct file *file);
static ssize_t  read_proc(struct file *filp, char __user *buffer, size_t length,loff_t * offset);
static ssize_t  write_proc(struct file *filp, const char *buff, size_t len, loff_t * off);


#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = etx_read,
    .write      = etx_write,
    .open       = etx_open,
    .unlocked_ioctl = etx_ioctl,
    .release    = etx_release,
};


#if ( LINUX_KERNEL_VERSION > 505 )
/*
** procfs operation sturcture
*/
static struct proc_ops proc_fops = {
        .proc_open = open_proc,
        .proc_read = read_proc,
        .proc_write = write_proc,
        .proc_release = release_proc
};
#else //LINUX_KERNEL_VERSION > 505
/*
** procfs operation sturcture
*/
static struct file_operations proc_fops = {
        .open = open_proc,
        .read = read_proc,
        .write = write_proc,
        .release = release_proc
};
#endif //LINUX_KERNEL_VERSION > 505
/*
** This function will be called when we open the procfs file
*/
static int open_proc(struct inode *inode, struct file *file)
{
    pr_info("proc file opend.....\t");
    return 0;
}
/*
** This function will be called when we close the procfs file
*/
static int release_proc(struct inode *inode, struct file *file)
{
    pr_info("proc file released.....\n");
    return 0;
}
/*
** This function will be called when we read the procfs file
*/
static ssize_t read_proc(struct file *filp, char __user *buffer, size_t length,loff_t * offset)
{
    pr_info("proc file read.....\n");
    if(len)
    {
        len=0;
    }
    else
    {
        len=1;
        return 0;
    }
    
    if( copy_to_user(buffer,etx_array,20) )
    {
        pr_err("Data Send : Err!\n");
    }
 
    return length;;
}
/*
** This function will be called when we write the procfs file
*/
static ssize_t write_proc(struct file *filp, const char *buff, size_t len, loff_t * off)
{
    pr_info("proc file wrote.....\n");
    
    if( copy_from_user(etx_array,buff,len) )
    {
        pr_err("Data Write : Err!\n");
    }
    
    return len;
}


/*
** This function will be called when we open the Device file
*/
static int etx_open(struct inode *inode, struct file *file)
{
        if((kernel_buffer = kmalloc(mem_size , GFP_KERNEL)) == 0){
            printk(KERN_INFO "Cannot allocate memory in kernel\n");
            return -1;
        }
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}
/*
** This function will be called when we close the Device file
*/
static int etx_release(struct inode *inode, struct file *file)
{
        kfree(kernel_buffer);
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}
/*
** This function will be called when we read the Device file
*/
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        copy_to_user(buf, kernel_buffer, mem_size);
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}
/*
** This function will be called when we write the Device file
*/
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        copy_from_user(kernel_buffer, buf, len);
        pr_info("Driver Write %s \n", buf);
        return len;
}
/*
** This function will be called when we write IOCTL on the Device file
*/
static long etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
         switch(cmd) {
                case WR_VALUE:
                        if( copy_from_user(&value ,(int32_t*) arg, sizeof(value)) )
                        {
                                pr_err("Data Write : Err!\n");
                        }
                        pr_info("Value = %d\n", value);
                        break;
                case RD_VALUE:
                        if( copy_to_user((int32_t*) arg, &value, sizeof(value)) )
                        {
                                pr_err("Data Read : Err!\n");
                        }
                        break;
                default:
                        pr_info("Default\n");
                        break;
        }
        return 0;
}
 

/*
** Module init function
*/
static int __init hello_world_init(void)
{
        int i;
        if ((alloc_chrdev_region(&dev, 0, 1, "test_dev")) < 0) {
          printk(KERN_INFO "Cannot allocate major number for device 1\n");
                return -1;
        };
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
        /*Creating cdev structure*/
        cdev_init(&etx_cdev,&fops);
        /*Adding character device to the system*/
        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }

        /*Creating struct class*/
        dev_class = class_create("test_class");
        if(IS_ERR(dev_class)){
            pr_err("Cannot create the struct class for device\n");
            goto r_class;
        }

        /*Creating device*/
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"test_device"))){
            pr_err("Cannot create the Device\n");
            goto r_device;
        }

        parent = proc_mkdir("test_drv_dir",NULL);
        
        if( parent == NULL )
        {
            pr_info("Error creating proc entry");
            goto r_device;
        }
        
        /*Creating Proc entry under "/proc/etx/" */
        proc_create("test_drv_proc", 0666, parent, &proc_fops);

        pr_info("Kernel Module Inserted Successfully...\n");
        return 0;
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;

  #if 0
        // printk(KERN_INFO "ValueETX = %d  \n", valueETX);
        // printk(KERN_INFO "cb_valueETX = %d  \n", cb_valueETX);
        // printk(KERN_INFO "NameETX = %s \n", nameETX);
        // for (i = 0; i < (sizeof arr_valueETX / sizeof (int)); i++) {
        //         printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
        // }
  #endif

        
}

/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
    proc_remove(parent);
    device_destroy(dev_class,dev);
    class_destroy(dev_class);
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("EmbeTronicX <embetronicx@gmail.com>");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("1.0");
