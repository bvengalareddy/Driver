#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/ioport.h>
#include <linux/errno.h>

MODULE_AUTHOR("Vengala Reddy");
MODULE_LICENSE("GPL");

static int mydev_open(struct inode *inode, struct file *file);
static int mydev_close(struct inode *inode, struct file *file);
static ssize_t mydev_read(struct file *file, char *buf, size_t count,
		loff_t *offset);
static ssize_t mydev_write(struct file *file, const char *buf, size_t count,
		loff_t *offset);


#define  MAX_BUF_SIZE  1024

typedef struct 
{
	char buf[1024];
	int noOfChars;
}mydev_t;

mydev_t mydev;

#define MYDEV_MAJOR_NUM   42
#define MYDEV_NAME        "mydev"

static struct file_operations mydev_ops =
{
read:mydev_read,
     write:mydev_write,
     open:mydev_open,
     release:mydev_close,
};

/*******************************************************************************
 * Name:init_module
 * Description:
 *******************************************************************************/
int mydev_init(void)
{
	int res;
	res = register_chrdev(MYDEV_MAJOR_NUM, MYDEV_NAME, &mydev_ops);
	if(res<0)
	{
		printk("<1>" "Registration Error %d\n",res);
		return res;
	}
	else
	{
		printk("<1>" "Registration success %d\n",res);
	}
	mydev.noOfChars=0;

	return 0;
}

/*******************************************************************************
 * Name:cleanup_module
 * Description:
 *******************************************************************************/
void mydev_cleanup(void)
{
	unregister_chrdev(MYDEV_MAJOR_NUM, MYDEV_NAME);
	printk(KERN_ALERT "good bye\n");

}

/*******************************************************************************
 * Name:mydev_open
 * Description:
 *******************************************************************************/
static int mydev_open(struct inode *inode, struct file * file)
{
	try_module_get(THIS_MODULE);
	file->private_data = &mydev;
	if (file->f_mode & FMODE_READ)
		printk("<1>" "open for read\n");
	if (file->f_mode & FMODE_WRITE)
		printk("<1>" "opened for write\n");

	return 0;	
}


/*******************************************************************************
 * Name:mydev_close
 * Description:
 *******************************************************************************/
static int mydev_close(struct inode *inode, struct file * file)
{
	module_put(THIS_MODULE);
	printk("<1>" "device closed\n");
	return 0;
}


/*******************************************************************************
 * Name:mydev_read
 * Description:
 *******************************************************************************/
static ssize_t mydev_read(struct file *file, char * buf,
		size_t count,  loff_t * offset)
{
	mydev_t *tdev = file->private_data;
	if (count>tdev->noOfChars) 
		count = tdev->noOfChars;
	copy_to_user(buf,tdev->buf,count);

	printk("<1>" "read called \n");
	return (ssize_t)count;
}

/*******************************************************************************
 * Name:mydev_write
 * Description:
 *******************************************************************************/
static ssize_t mydev_write(struct file * file, const char * buf,
		size_t count,loff_t * offset)
{
	mydev_t *tdev = file->private_data;
	if (count > MAX_BUF_SIZE) 
		count = MAX_BUF_SIZE;
	copy_from_user(tdev->buf,buf,count);
	tdev->noOfChars=count;
	printk("<1>" "write called \n");
	return count;
}

module_init(mydev_init);
module_exit(mydev_cleanup);
