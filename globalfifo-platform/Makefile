ifneq ($(KERNELRELEASE),)

obj-m := globalfifo-platform.o

else

#KDIR := /home/daniel/linux-2.6.38
KDIR := /lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.mod.o *.symvers
	
endif
