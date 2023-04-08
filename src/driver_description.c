#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#define DRIVER_AUTHOR "Potato <user@potato.inc>"
#define DRIVER_DESC "A sample driver for intel x86_64"

static int __init init_hello(void) {
  printk(KERN_INFO "Hello kernel am back again\n");
  return 0;
}

static void __exit exit_hello(void) {
  printk(KERN_INFO "Driver exits the kernel\n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
// MODULE_SUPPORTED_DEVICE("tty"); // use a dev device /dev/--
