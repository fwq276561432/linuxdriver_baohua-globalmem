/*======================================================================
    A globalmem driver as an example of char device drivers  
   
    The initial developer of the original code is Baohua Song
    <author@linuxdriver.cn>. All Rights Reserved.
======================================================================*/
#include <stdio.h>
#include <fcntl.h>

int main()
{
int dev_fd;
//int ppos=48;
char read_buf[100];
char write_buf[]="hello world,how are you?i love youu!may i help ?no thank you";
dev_fd=open("/dev/globalmem",O_RDWR | O_NONBLOCK);
	if(dev_fd==-1)
	{
		printf("cant open file \n");
		exit(1);
	}
	lseek(dev_fd,0,0);
	write(dev_fd,write_buf,60/*,&ppos*/);

//	printf("ppos=%d \n",ppos);
	lseek(dev_fd,24,0);
	read(dev_fd,read_buf,60/*,0*/);

	printf("read_buf=%s \n",read_buf);

	close(dev_fd);
	return 0;
}
