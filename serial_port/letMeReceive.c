#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int set_interface_attribs(int fd, int speed)
{
    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) {
        printf("Error from tcgetattr: %s\n", strerror(errno));
        return -1;
    }
    cfsetospeed(&tty, (speed_t)speed);
    cfsetispeed(&tty, (speed_t)speed);
    tty.c_cflag |= (CLOCAL | CREAD);    /* ignore modem controls */
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;         /* 8-bit characters */
    tty.c_cflag &= ~PARENB;     /* no parity bit */
    tty.c_cflag &= ~CSTOPB;     /* only need 1 stop bit */
    tty.c_cflag &= ~CRTSCTS;    /* no hardware flowcontrol */
    /* setup for non-canonical mode */
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;
    /* fetch bytes as they become available */
    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 1;
    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        printf("Error from tcsetattr: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

void set_mincount(int fd, int mcount)
{
    struct termios tty;
    if (tcgetattr(fd, &tty) < 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return;
    }
    tty.c_cc[VMIN] = mcount ? 1 : 0;
    tty.c_cc[VTIME] = 5;        /* half second timer */
    if (tcsetattr(fd, TCSANOW, &tty) < 0)
        printf("Error tcsetattr: %s\n", strerror(errno));
}


<<<<<<< HEAD
int main(int argc, char *argv[])
{
    char *port = "/dev/ttyUSB0";
    if (argc > 1) port = argv[1];
=======
int main()
{
    char *port = "/dev/ttyUSB1";
>>>>>>> 61ac7beca5c725105c48563449834a4fb3bc8b63
    int fd;
    
    fd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd == -1) { perror("Unable to open /dev/ttyUSB1"); return -1; }

    /*baudrate 115200, 8 bits, no parity, 1 stop bit */
    set_interface_attribs(fd, B115200);
    //set_mincount(fd, 0);                /* set to pure timed read */
   
    do {
        unsigned char buf[80];
        int n;

        n = read(fd, buf, sizeof(buf) - 1);
<<<<<<< HEAD
        tcflush(fd, TCOFLUSH);
=======
>>>>>>> 61ac7beca5c725105c48563449834a4fb3bc8b63
        if (n > 0) {
            buf[n] = 0;
            printf("Read %d: \"%s\"\n", n, buf);
        /*
            unsigned char *p;
            printf("Read %d:", rdlen);
            for (p = buf; rdlen-- > 0; p++)
                printf(" 0x%x", *p);
            printf("\n");
        */
        } else if (n < 0) {
            printf("Error from read: %d: %s\n", n, strerror(errno));
        }
        /* repeat read to get full message */
    } while (1);
}
