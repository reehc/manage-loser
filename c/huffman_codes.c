#include <stdio.h>
#include <stdlib.h>

#define MAXBIT 10
#define VERY_LARGE_WEIGHT 1000000

typedef struct huffman_node {
    int weight;
    int parent, lchild, rchild;
} huffman_node;

typedef struct huffman_code {
    int bit[MAXBIT];
    int start;
} huffman_code;

huffman_code *huffman_coding(huffman_node *, huffman_code *, int *, int n);
void tree(huffman_node *tree);
void enqueue(int *, int );
int dequeue(int *, int *);

int main() {
    int queue[] = {1, -1};
    int ii, j;

    enqueue(queue, 12);
    printf("%d\n", queue[1]);



    huffman_node *node;
    huffman_code *code;
    int i[] = {1, 2, 3, 4, 5};

    huffman_code *fixed = huffman_coding(node, code, i, 5);
    for (int i = 0; i < 5; ++i) {
        printf("code[%d]: ", i);
        for (int j = 0; j < MAXBIT; ++j) printf("%d", fixed[i].bit[j]);
        printf("\n");
    }
    return 0;
}

/*
 * Caution!!!
 *
 * When transfer a pointer like this: void function001(void *p);
 *
 * YOU CAN ONLY CHANGE THE CONTENT WHAT THIS POINTER IS POINTING TO!
 * YOU CANNOT CHANGE WHAT THIS POINTER IS POINTING TO!
 * BE AWARE~~~
 *
 * NOW I AM GOING TO GIVE A POINTER RETURN AND I CAN FIX THIS!
 * THOUGH NOT PERFECT.
 *
 * */
huffman_code *huffman_coding(huffman_node *ht, huffman_code *hc, int *w, int n) {
    if (n <= 1) return NULL;
    int m = 2*n - 1;
    ht = (huffman_node *)malloc(m * sizeof(huffman_node));

    huffman_node *p = ht;
    int i;
    // initialize leave nodes
    for (i = 0; i < n; ++i, ++p, ++w) {
        (*p).weight = *w;
        (*p).lchild = -1; (*p).rchild = -1; (*p).parent = -1;
    }
    // initialize branch nodes
    for ( ; i < m; ++i, ++p) {
        (*p).weight = 0;
        (*p).lchild = -1; (*p).rchild = -1; (*p).parent = -1;
    }
    // huffman-tree generating!
    for (int i = n; i < m; ++i) {
        int m1, m2, x1, x2;
        m1 = m2 = VERY_LARGE_WEIGHT;
        x1 = x2 = 0;
        for (int j = 0; j < i; ++j) {
            if (ht[j].parent == -1 && ht[j].weight < m1) {
                m2 = m1; m1 = ht[j].weight; x1 = j;
            } else if (ht[j].parent == -1 && ht[j].weight < m2) {
                m2 = ht[j].weight; x2 = j;
            }
        }
        // MERGE!
        ht[x1].parent = i; ht[x2].parent = i;
        ht[i].lchild = x1; ht[i].rchild = x2;
        ht[i].weight = m1 + m2;
    }

    for (int iii = 0; iii < m; ++iii) {
        printf("index:%d --> weight:%2d\tl:%2d\tr:%2d\tparent:%2d\n", iii, ht[iii].weight, ht[iii].lchild, ht[iii].rchild, ht[iii].parent);
    }
    tree(ht);

    // Coding!
    int start, f, c;
    hc = (huffman_code *)malloc(n * sizeof(huffman_code));
    for (int i = 0; i < n; ++i) {
        start = n - 1;
        for (c = i, f = ht[i].parent; f != -1; c = f, f = ht[f].parent) {
            if (ht[f].lchild = c) hc[i].bit[start--] = 0;
            else hc[i].bit[start--] = 1;
        }
        hc[i].start = start + 1;
    }

    return hc;
}

void enqueue(int *queue, int data) {
    if (queue[0] == -1) {
        queue[0] = data;
        return;
    }
    int i = 0;
    while(!(queue[i] != -1 && queue[i+1] == -1)) {i++;}
    queue[i+1] = data;
}

int dequeue(int *queue, int *i) {
    if (queue[0] == -1) return 0;
    *i = queue[0];
    int index = 0;
    while (queue[index] != -1) {
        queue[index] = queue[index+1];
        index++;
    }
    //queue[index] = -1;
    return 1;
}

void tree(huffman_node *tree) {
    int index = 0;
    int *queue = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < 100; ++i) queue[i] = -1;
    while (tree[index].parent != -1) index = tree[index].parent;
    enqueue(queue, index);
    while(queue[0] != -1) {
        int j;
        int *temp = (int *)malloc(100 * sizeof(int));
        for (int i = 0; i < 100; ++i) temp[i] = -1;
        for (int i = 0; queue[i] != -1; ++i) printf(" %d ", queue[i]);
        printf("\n");
        while (dequeue(queue, &j)) {
            //printf("NODE->%d ", j);
            if (tree[j].lchild != -1) enqueue(temp, tree[j].lchild);
            if (tree[j].rchild != -1) enqueue(temp, tree[j].rchild);
        }
        free(queue);
        queue = temp;
        putchar('\n');
    }
}
