#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
#include <linux/sched.h>
#include "01time.h"
MODULE_LICENSE("Dual BSP/GPL");

static struct timeval curr_time;

void test_time(void)
{
	int my_timestamp;
	do_gettimeofday(&curr_time);
	my_timestamp = cpu_to_le32(curr_time.tv_sec); // record timestamp
	printk(KERN_ALERT "my_timestamp=%d\n", my_timestamp);
}

EXPORT_SYMBOL(test_time);
