#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
MODULE_LICENSE("Dual BSP/GPL");

static struct timeval curr_time;

static int hello_init(void)
{
	int my_timestamp;
	do_gettimeofday(&curr_time);
	my_timestamp = cpu_to_le32(curr_time.tv_sec); // record timestamp
	printk(KERN_ALERT "my_timestamp=%d\n", my_timestamp);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, 00start\n");
}

module_init(hello_init);
module_exit(hello_exit);
