#include <stdio.h>
#include "nothing.h"
int main(int argc, char *argv[])
{
#ifdef PRINT_ME
    printf("ok\n");
#endif
    printf("I am done.\n");
    return 0; 
}
