#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Byshenko Daniil <byda@proronmail.com>");
MODULE_DESCRIPTION("A Simple Antivirus Module");

void print_log(char* log)
{
	printk(KERN_ALERT "[Antivirus] %s\n", log);
}

static int __init hello_init(void)
{
    print_log("Hello, world!");

  /*
   * If you return a non-zero value, it will be interpreted
   * as a sign of an error that occurred during the operation of init_module; 
   * as a result, the module will not be loaded. 
   */
    return 0;
}

static void __exit hello_cleanup(void)
{
    print_log("Goodbye world");
}

module_init(hello_init);
module_exit(hello_cleanup);