
ifneq ($(KERNELRELEASE),) 
obj-m := my_sleep.o
else 
	KDIR := $(HOME)/ISO_II/linux_kernel/linux-stable
all: 
	$(MAKE) -C $(KDIR) M=$$PWD 
endif
