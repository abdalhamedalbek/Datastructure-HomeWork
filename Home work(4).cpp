#include <stdio.h>

#define MAX 50

typedef struct {
    int arr[MAX];
    int size;
    int isMax;
} Heap;

void swap(int *a, int *b){
    int t = *a; *a = *b; *b = t;
}

int better(Heap *h, int a, int b){
    return h->isMax ? a > b : a < b;
}

void insert(Heap *h, int val){
    int i = h->size++;
    h->arr[i] = val;

    while(i>0){
        int p = (i-1)/2;
        if(better(h, h->arr[i], h->arr[p])){
            swap(&h->arr[i], &h->arr[p]);
            i = p;
        } else break;
    }
}

int extract(Heap *h){
    int root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while(1){
        int l = 2*i+1, r = 2*i+2, best = i;
        if(l<h->size && better(h, h->arr[l], h->arr[best])) best = l;
        if(r<h->size && better(h, h->arr[r], h->arr[best])) best = r;
        if(best != i){
            swap(&h->arr[i], &h->arr[best]);
            i = best;
        } else break;
    }
    return root;
}
