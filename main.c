#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>
#include <linux/usb_usual.h>
/* usb driver for reading usb vendor and product for sandisk
 * author : github.com/Punixcorn
 */

/* probe function ( called when device is inserted ) */
static int pen_probe(struct usb_interface* interface,
                     const struct usb_device_id* id) {
    printk(KERN_INFO,
           "[*] Punixcorn::Sandisk Pen drive (%04X:%04X) plugged in\n",
           id->idVendor, id->idProduct);
    return 0;  // return 0 means we manage device
}

/* disconnect function */
static void pen_disconnect(struct usb_interface* interface) {
    printk(KERN_INFO, "[*] Punixcorn::Sandisk Pen Drive removed");
}

/* usb driver id */
static struct usb_device_id pen_table[] = {
    {USB_DEVICE(0x0781,
                0x5597)}, /* USB ID for vendorid : product id (from lsusb)*/
    {}                    /* NULL ENTRY */
};

MODULE_DEVICE_TABLE(usb, pen_table);

/* usb driver */
static struct usb_driver pen_driver = {
    .name = "Punixcorn::usb driver",
    .id_table = pen_table,         // usb device id
    .probe = pen_probe,            // usb probe function
    .disconnect = pen_disconnect,  // usb disconnect function
};

static int __init pen_init(void) {
    int ret = -1;
    printk(KERN_INFO, "[*] Punixcorn::Sandisk driver Constructor\n");
    printk(KERN_INFO, "\tRegistering Driver with Kernel");
    ret = usb_register(&pen_driver);
    printk(KERN_INFO, "\tRegistering complete\n");
    return ret;
};

static void __exit pen_exit_func(void) {
    printk(KERN_INFO, "[*] Punixcorn::Sandisk driver Deconstruction\n");
    usb_deregister(&pen_driver);
    printk(KERN_INFO, "\tDriver Deconstruction complete\n");
};

module_init(pen_init);
module_exit(pen_exit_func);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oh Hyun Wo <ohyunwoods663@gmail.com>");
MODULE_DESCRIPTION(
    "linux usb driver for printing info about Sandisk usb device");
MODULE_VERSION("0.1");
