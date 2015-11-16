#include <linux/module.h>
#include <linux/init.h>

#include "02scull.h"

void scull_cleanup_module(void)
{
	printk(KERN_ALERT "scull cleanup\n");
}

int scull_init_module(void)
{
	int result;
	printk(KERN_ALERT "scull init\n");
	return 0;
	goto fail;
fail:
	scull_cleanup_module();
	return result;
}

module_init(scull_init_module);
module_exit(scull_cleanup_module);
