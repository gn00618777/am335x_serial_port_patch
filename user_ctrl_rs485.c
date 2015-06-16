#include <linux/serial.h>
#include <stdio.h>
#include <fcntl.h>

/* Driver-specific ioctrls: */
#define TIOCGRS485	0x542E
#define TIOCSRS485	0x542F

int main(){

   int fd = open("/dev/ttyO2", O_RDWR);

   if (fd < 0)
	printf("Error open tty\n");

   struct serial_rs485 rs485conf;

   /* Enable RS485 mode: */
  //rs485conf.flags &= ~(SER_RS485_ENABLED); /* Disable RS485 mode */
  rs485conf.flags |= SER_RS485_ENABLED;
  rs485conf.flags |= SER_RS485_RTS_ON_SEND;

  if (ioctl (fd, TIOCSRS485, &rs485conf) < 0) {

	printf("Error ioctl\n");

  }
  
  close(fd);

}
