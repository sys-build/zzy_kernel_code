#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>
#include <linux/sched.h>
#include "01proc_info.h"
MODULE_LICENSE("Dual BSP/GPL");

void print_process_info(void)
{
	printk(KERN_ALERT "pid=%d, comm=%s\n", current->pid, current->comm);
}

EXPORT_SYMBOL(print_process_info);
