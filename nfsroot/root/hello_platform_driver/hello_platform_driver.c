#include <linux/module.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/of.h>


/******************************************************************************
   ******************* DEFINICION DE FILE OPERATIONS **************************
******************************************************************************/

static int my_dev_open(struct inode *inode, struct file *file)  {
        pr_info("my_dev_open() is called.\n");
        return 0;
};

static int my_dev_close(struct inode *inode, struct file *file)  {
        pr_info("my_dev_close() is called.\n");
        return 0;
};

static long my_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)  {
        pr_info("my_dev_ioctl() is called. cmd = %d, arg = %ld\n", cmd, arg);
        return 0;
};


/******************************************************************************
   **************** DEFINICION DE ESTRUCTURAS  ********************************
******************************************************************************/
/* Definicion de file operations */
static const struct file_operations my_dev_fops = {
        .owner = THIS_MODULE,
        .open = my_dev_open,
        .release = my_dev_close,
        .unlocked_ioctl = my_dev_ioctl,
};

/* Definicion de misc device */
static struct miscdevice helloworld_miscdevice = {
        .minor = MISC_DYNAMIC_MINOR,
        .name = "mydev",
        .fops = &my_dev_fops,
};


/******************************************************************************
   *********** DEFINICION DE FUNCIONES PROBE() Y REMOVE() *********************
******************************************************************************/

/* Definicion de funcion probe() */
static int __init my_probe(struct platform_device *pdev)  {
        int ret_val;
 
        pr_info("my_probe() function is called.\n");
        ret_val = misc_register(&helloworld_miscdevice);
        if (ret_val != 0) {		
               pr_err("could not register the misc device mydev");
               return ret_val;
        }
        pr_info("mydev: got minor %i\n",helloworld_miscdevice.minor);
        return 0;
};

/* Add remove() function */
static int __exit my_remove(struct platform_device *pdev)  {
        pr_info("my_remove() function is called.\n");
        misc_deregister(&helloworld_miscdevice);
        return 0;
};

/******************************************************************************
   ************************ OF MATCH STYLE ************************************
******************************************************************************/

/* Declare a list of devices supported by the driver */
static const struct of_device_id my_of_ids[] = {
        { .compatible = "imd,mse_driver", },
        {/*sentinel*/},
};
MODULE_DEVICE_TABLE(of, my_of_ids);


/******************************************************************************
   ***************** DECLARACION DE PLATFORM DRIVER ***************************
******************************************************************************/
/* Define platform driver structure */
static struct platform_driver my_platform_driver = {
        .probe = my_probe,
        .remove = my_remove,
        .driver = {
	        .name = "hello_platform_driver",	
                .of_match_table = my_of_ids,
                .owner = THIS_MODULE,
        }
};

/* Register your platform driver */
module_platform_driver(my_platform_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gonzalo Sanchez <gonzalo@sanchez.com>");
MODULE_DESCRIPTION("Ejemplo de un platform driver sencillo");
