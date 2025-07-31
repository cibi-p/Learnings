#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>

static struct gpio_desc *led, *button;

#define IO_LED 21
#define IO_BUTTON 20

#define IO_OFFSET 512

int __init my_init(void)
{
  int status;
	printk("hello - Hello, Kernel!\n");

  led = gpio_to_desc(IO_LED + IO_OFFSET);
  if (!led) {
      printk("no gpio detected1");
      return -ENODEV;
  }
  button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
  if (!button) {
      printk("no gpio detected");
      return -ENODEV;
  }

  status = gpiod_direction_output(led, 0);
  if (status) {
      printk("gpio direction error");
      return -ENODEV;
  }
  
  status = gpiod_direction_input(button);
  if (status) {
      printk("gpio direction error");
      return -ENODEV;
  }

  gpiod_set_value(led, 1);
	return 0;
}

void __exit my_exit(void)
{
	printk("hello - Goodbye, Kernel!\n");
  gpiod_set_value(led, 0);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("hari P");
MODULE_DESCRIPTION("A simple hello world linux Kernel Module");
