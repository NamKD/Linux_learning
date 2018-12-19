#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int __init example_init(void)
{
	printk(KERN_INFO "namkd\n");
	return 0;
}

static void __exit example_exit(void)
{
	printk("goodgag\n");
}

module_init(example_init);
module_exit(example_exit);
