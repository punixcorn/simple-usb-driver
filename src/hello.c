#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
MODULE_LICENSE("bsd");
static int hello_init(void) {
  printk(KERN_INFO "Hello world\n");
  return 0;
}

static void hello_exit(void) { printk(KERN_INFO "goodbye kernel\n"); }

module_init(hello_init);
module_exit(hello_exit);
