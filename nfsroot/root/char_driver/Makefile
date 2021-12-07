
ifneq ($(KERNELRELEASE),) 
obj-m := holamundo_char_driver.o
else 
	KDIR := $(HOME)/ISO_II/linux_kernel/linux-stable
all: 
	$(MAKE) -C $(KDIR) M=$$PWD 
endif
