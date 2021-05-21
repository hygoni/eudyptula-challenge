#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>
#include <linux/usb.h>

int __init helloworld_init(void)
{
	printk(KERN_DEBUG "Hello, World!\n");
	return 0;
}

void __exit helloworld_exit(void)
{
	printk(KERN_DEBUG "HelloWorld - made By hyeyoo\n");
}

static const struct usb_device_id usb_keyboards[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
			USB_INTERFACE_SUBCLASS_BOOT,
			USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{ } /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, usb_keyboards);

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_LICENSE("GPL");
