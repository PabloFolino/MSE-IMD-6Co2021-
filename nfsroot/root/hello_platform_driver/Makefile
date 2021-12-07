
ifneq ($(KERNELRELEASE),) 
obj-m := hello_platform_driver.o
else 
	KDIR := $(HOME)/ISO_II/linux_kernel/linux-stable
all: 
	$(MAKE) -C $(KDIR) M=$$PWD 
endif
