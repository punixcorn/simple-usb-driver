/*
 run with
  sudo insmod hello.ko mystr="hecker1337found" myintarr=-1,-1
  and see
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("potato");

/* == Variables == */
/*
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits,
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

static int arr_argc = 0;

static int myint = 3;
module_param(myint, int, 0);
MODULE_PARM_DESC(myint, "an interger"); // description of the variables
static char *mystr = "blah";

module_param(mystr, charp,
             0000 /* or S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP or 0 */);
MODULE_PARM_DESC(mystr,
                 "a char * aka a string"); // description of the variables

/* == arrays == */
/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */
int myintarr[2] = {-1, -1};
module_param_array(myintarr, int, NULL, 0);
MODULE_PARM_DESC(myintarr, "an interger array");

static int __init hello_init(void) {
  int i;
  printk(
      KERN_INFO
      "Hello Kernel i have some info to display\n==========================\n");
  printk(KERN_INFO "my int is %d\n", myint);

  printk(KERN_INFO "my words are %s\n", mystr);
  for (i = 0; i < (sizeof myintarr / sizeof(int)); i++) {
    printk(KERN_INFO "myintarr[%d] = %d\n", i, myintarr[i]);
  }
  printk(KERN_INFO "got %d args for the int array\n", arr_argc);
  return 0;
}

static void __exit hello_exit(void) {
  printk(KERN_INFO "infomation passed on,\nkilling module...\n");
}

module_init(hello_init);
module_exit(hello_exit);
