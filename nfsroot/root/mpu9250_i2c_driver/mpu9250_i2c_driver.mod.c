#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xefc7e154, "module_layout" },
	{ 0x7851cd58, "i2c_del_driver" },
	{ 0x85cef7e6, "i2c_register_driver" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x4174e462, "i2c_transfer_buffer_flags" },
	{ 0x61885312, "misc_register" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe32e5db7, "devm_kmalloc" },
	{ 0x95cfe45e, "misc_deregister" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xc5850110, "printk" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmse,my_mpu9250");
MODULE_ALIAS("of:N*T*Cmse,my_mpu9250C*");

MODULE_INFO(srcversion, "57806ABD0B4B5C7CFB7D1F9");
