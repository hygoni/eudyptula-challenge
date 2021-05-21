#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/string.h>

#define DEVICE_NAME "eudyptula"

static ssize_t eudyptula_read(struct file *filp, char __user *buf,
		size_t count, loff_t *ppos)
{
	if (*ppos == strlen(DEVICE_NAME))
		return 0;

	count = min(count, strlen(DEVICE_NAME));
	if (copy_to_user(buf, DEVICE_NAME, count)) {
		return -EFAULT;
	}
	*ppos += count;
	return count;
}

static ssize_t eudyptula_write(struct file *filp,  const char __user *buf,
		size_t count, loff_t *ppos)
{
	/* not equal to DEVICE_NAME */
	if (strncmp(buf, DEVICE_NAME, strlen(DEVICE_NAME))) {
		return -EINVAL;
	}
	return 0;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = eudyptula_read,
	.write = eudyptula_write,
};

static struct miscdevice eudyptula = {
	.minor = 119,
	.name = DEVICE_NAME,
	.fops = &fops,
};

int __init eudyptula_init(void)
{
	printk(KERN_DEBUG "Hello, I am %s!\n", DEVICE_NAME);
	printk(KERN_DEBUG "This is a misc char driver\n");
	if (misc_register(&eudyptula)) {
		printk(KERN_DEBUG "failed to register\n");
		return 1;
	}
	printk(KERN_DEBUG "successfully registered.\n");
	return 0;
}

void __exit eudyptula_exit(void)
{
	misc_deregister(&eudyptula);
	printk(KERN_DEBUG "%s, made By hyeyoo\n", DEVICE_NAME);
}

module_init(eudyptula_init);
module_exit(eudyptula_exit);

MODULE_LICENSE("GPL");
