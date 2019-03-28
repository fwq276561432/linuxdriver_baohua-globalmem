
1. linuxdriver_baohua-globalmem : 1st code sync to github
2. linuxdriver_baohua : 1st version code
3. linuxdriver_baohua-v2/training :2nd version code
3.1 linuxdriver_baohua-v2/kernel/drivers/vmem_disk/vmem_disk.c : many api errors of block driver;


2.2. 08/pollmonitor.c : while(1) has side effect that many outputs;

2.3. linuxdriver_baohua-globalmem/globalmem_test/Makefile is a simple makefile
	08/pollmonitor/Makefile is a very easyToUse and powerful makefile
	training/kernel/drivers/second : this makefile deal both;

2.5.10/S3C2410-rtc : better build in the real kernel code --TBD
	10/second-timer : timer api errors  --TBD

#include <linux/slab.h>>>---/* kmalloc() */
init_MUTEX(x)       ---->  sema_init(x, 1)
