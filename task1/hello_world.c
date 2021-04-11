#include <linux/module.h>
#include <linux/kernel.h>

int __init helloworld_init(void)
{
	printk(KERN_DEBUG "Hello, World!");
	return 0;
}

void __exit helloworld_exit(void)
{
	printk(KERN_DEBUG "HelloWorld - made By hyeyoo");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_LICENSE("GPL");
