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

dev_t dev = 0;
static struct class *dev_class;
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
    device_destroy(dev_class,dev);
    class_destroy(dev_class);
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}
 
module_init(hello_world_init);
module_exit(hello_world_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("EmbeTronicX <embetronicx@gmail.com>");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("1.0");
