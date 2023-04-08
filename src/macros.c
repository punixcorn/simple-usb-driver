#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int hello_data __initdata = 3;

static int __init hello_init(void) {
  printk(KERN_INFO "Hello Kernel am back number %d\n", hello_data);
  return 0;
}

static void __exit hello_exit(void) { printk(KERN_INFO "Leaving Kernel\n"); }

module_init(hello_init);
module_exit(hello_exit);
