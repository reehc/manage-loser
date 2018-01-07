/* who.c - a first version of my who program
 *	   open, read UTMP f....NONONO, there's a interface, and show results
 */

#include <stdio.h>
#include <stdlib.h>
#include <utmpx.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST	/* include remote machine on output */

void show_info(struct utmpx * utbufp);

int main()
{
    struct utmpx current_record; /* read info into here */
    int utmpxfd;		 /* read from this descriptor */
    int reclen = sizeof(current_record);

    if( (utmpxfd = open(UTMPX_FILE, O_RDONLY)) == -1){
        perror(UTMPX_FILE);	/* UTMPX_FILE in utmpx.h */
    	exit(0);
    }

    while(read(utmpxfd, &current_record, reclen) == reclen)
	show_info(&current_record);
    close(utmpxfd);
    return 0;
}

void show_info(struct utmpx * utbufp)
{
    printf("%s", utbufp->ut_user);
    printf(" ");
    printf("%s", utbufp->ut_id);
    printf(" ");
    printf("% - 8.8s", utbufp->ut_line);
    printf(" ");
    printf("\n");
}
