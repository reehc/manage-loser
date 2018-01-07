#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void show(int *base, size_t n);
size_t partition(int *base, size_t nele);
void qsort_serial(int *base, size_t nele);

int main(int argc, char *argv[])
{
    if (argc < 3) {
	printf("./a.out array_length show_nums\n");
	exit(0);
    }
    srand(time(NULL));
    int length = atoi(argv[1]);
    int array[length];
    for (int i = 0; i < length; i++)
        array[i] = rand()%10;
    show(array, atoi(argv[2]));
    qsort_serial(array, length);
    show(array, atoi(argv[2]));
    return 0;
}

void show(int *base, size_t n)
{
    printf("[%d", base[0]);
    for (int i = 1; i < n; i++)
    {
		printf(", %d", base[i]);
    }
    printf("]\n");
}

size_t partition(int *base, size_t nele)
{
    int pivot = base[nele-1];
    int i = -1; 
    for (int j = 0; j < nele; j++)
    {
		if (base[j] <= pivot)
		{
			i++;
			swap(base + i, base + j);
		}
    }
	// this line kills me. QAQ.
	if (i < nele - 1) swap(&base[++i], &base[nele-1]);
    return i;
}

void qsort_serial(int *base, size_t nele)
{
    if (nele <= 1) return;
    if (nele == 2) {
		if (base[0] > base[1]) swap(base, base+1);
		return;
    }

    size_t m = partition(base, nele);
    if (m > 1) qsort_serial(base, m);
    if (nele-1 > m+1) qsort_serial(base+m+1, nele-m-1);
}

void swap(int *x, int *y)
{
	int temp_x = *x;
    int temp_y = *y;
    *x = temp_y;
    *y = temp_x;
}
