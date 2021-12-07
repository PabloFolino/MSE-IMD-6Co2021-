
ifneq ($(KERNELRELEASE),) 
obj-m := simple_platform_driver.o
else 
	KDIR := $(HOME)/ISO_II/linux_kernel/linux-stable
all: 
	$(MAKE) -C $(KDIR) M=$$PWD 
endif
