#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "config.h"

#ifdef USE_MCHEER
    #include "math/mcheer.h"
#else

#endif

int main(int argc, char *argv[]) {
#ifdef USE_MCHEER
	printf("\tInverse of argc: %d.\n", change(argc));
	printf("DEFINED USE_MCHEER!\n");
#else
	printf("NO MCHEER---\n");
#endif

	return 0;
}
