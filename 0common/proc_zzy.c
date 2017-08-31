#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>

static long zzy_test_proc = 0;
static char test_buf[2048];
static int zzy_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%ld\n", zzy_test_proc);
	return 0;
}

int zzy_write(struct file *filp, const char *buf, size_t count, loff_t *offp)
{
	memset(test_buf, 0, 2048);
	copy_from_user(test_buf, buf, count);
	kstrtol(test_buf, 10, &zzy_test_proc);
	return count;	
}

static int zzy_open(struct inode *inode, struct file *file)
{
	return single_open(file, zzy_show, NULL);
}

static const struct file_operations zzy_fops = {
	.owner      = THIS_MODULE,
	.open       = zzy_open,
	.read       = seq_read,
	.write      = zzy_write,
	.llseek     = seq_lseek,
	.release    = single_release,
};

static int __init zzy_init(void)
{
	printk(KERN_INFO "Loading zzy module, zzy = %ld.\n", zzy_test_proc);
	proc_create("zzy", 0, NULL, &zzy_fops);
	return 0;
}

static void __exit zzy_exit(void)
{
	remove_proc_entry("zzy", NULL);
	printk(KERN_INFO "Unloading zzy module.\n");
}

module_init(zzy_init);
module_exit(zzy_exit);

MODULE_LICENSE("GPL");
