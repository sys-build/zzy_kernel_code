#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
#include <linux/sched.h>
#include "01time.h"
#include "01proc_info.h"
MODULE_LICENSE("Dual BSP/GPL");

static int hello_init(void)
{
	print_process_info();
	test_time();
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, 00start\n");
}

module_init(hello_init);
module_exit(hello_exit);
