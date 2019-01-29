ifneq ($(KERNELRELEASE),)

obj-m := hello.o

else

#KDIR := /lib/modules/3.11.0-15-generic/build
KDIR := /lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.mod.o *.symvers *.mod.c *.order
	
endif
