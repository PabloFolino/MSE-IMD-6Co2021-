
ifneq ($(KERNELRELEASE),) 
obj-m := mpu9250_i2c_driver.o
else 
	KDIR := $(HOME)/ISO_II/linux_kernel/linux-stable
all: 
	$(MAKE) -C $(KDIR) M=$$PWD 
endif
