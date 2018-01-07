#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum {
    FAILED,
    PASS,
    NOT_BAD,
    OK,
    GOOD
};

int decision(int score) {
    if (score < 60)
        return FAILED;
    else if (score < 70)
        return PASS;
    else if (score < 80)
        return NOT_BAD;
    else if (score < 90)
        return OK;
    else
        return GOOD;
}

int huffman_decision(int score) {
    if (score < 80) {
        if (score < 70) {
            if (score < 60)
                return FAILED;
            else
                return PASS;
        } else
            return NOT_BAD;
    } else if (score < 90)
        return OK;
    else
        return GOOD;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("test_scale needed.\n");
        return 0;
    }
    printf("%d\n", atoi(argv[1]));
    int test_scale = atoi(argv[1]);
    srand(time(NULL));

    clock_t t1 = clock();
    printf("NORMAL DECISION START...\n");
    for(int i = 0; i < test_scale; ++i) {
        decision(rand() % 101);
    }
    clock_t t2 = clock();
    printf("HUFFMAN DECISION START...\n");
    for(int i = 0; i < test_scale; ++i) {
        huffman_decision(rand() % 101);
    }
    clock_t t3 = clock();

    printf("RESULT:\n"
           "%.2fms used for algorithm 1\n"
           "%.2fms used for algorithm 2\n",
           1000.0 * (t2-t1)/CLOCKS_PER_SEC,
           1000.0 * (t3-t2)/CLOCKS_PER_SEC);
}
