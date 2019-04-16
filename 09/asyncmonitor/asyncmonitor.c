/*======================================================================
    A test program to access /dev/second
    This example is to help understand async IO 
    
    The initial developer of the original code is Baohua Song
    <author@linuxdriver.cn>. All Rights Reserved.
======================================================================*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

/*接收到异步读信号后的动作*/
void input_handler(int signum)
{
  printf("receive a signal from globalfifo,signalnum:%d\n",signum);
}


void xxx_handler(int signum,siginfo_t *info,void *myact)
{
	printf("Receive signal number:%d\n",signum);
	printf("si_signo:%d\n", info->si_signo);
	printf("si_code:%d\n", info->si_code);
	printf("si_value int:%d\n",info->si_value.sival_ptr);
	printf("si_value void*:%X\n",(unsigned long)info->si_value.sival_ptr);
	printf("si_errno:%d\n", info->si_errno);
	printf("si_pid:%d\n", info->si_pid);
	printf("si_uid:%d\n", info->si_uid);
	printf("si_addr:%X\n",(unsigned long)info->si_addr);
	printf("si_status:%d\n", info->si_status);
	printf("si_band:%d\n", info->si_band);
}


main()
{
  int fd, oflags;
  fd = open("/dev/globalfifo", O_RDWR, S_IRUSR | S_IWUSR);
  if (fd !=  - 1)
  {
//    signal(SIGIO, input_handler); //让input_handler()处理SIGIO信号

	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction=xxx_handler;
	act.sa_flags=SA_SIGINFO;
	if(sigaction(SIGIO,&act,NULL) < 0)
	{
	        printf("install sigal error\n");
	}
    fcntl(fd, F_SETOWN, getpid());
    oflags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, oflags | FASYNC);
	fcntl(fd, F_SETSIG, SIGIO);
    while(1)
    {
    	sleep(100);
    }
  }
  else
  {
    printf("device open failure\n");
  }
}
