#include <linux/init.h>
#include <linux/module.h>
#include <asm/current.h> // used to get the PID
MODULE_LICENSE("Dual BSD/GPL");
static int hello_init(void)
{
    // EX: 1 Printing Hello World
    printk(KERN_ALERT "Hello, world\n");

    // Ex: 2 THe current is defined in asm/current.h, which gives the pid
    printk(KERN_INFO "The Process is \"%s\" (pid %i)\n", current->comm, current->pid);
    return 0;
}
static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);