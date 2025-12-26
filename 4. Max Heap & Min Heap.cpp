#include <stdio.h>

#define MAX 50

int heap[MAX], size = 0;

void insert(int val) {
    int i = size++;
    heap[i] = val;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int deleteRoot() {
    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            int t = heap[i];
            heap[i] = heap[largest];
            heap[largest] = t;
            i = largest;
        } else break;
    }
    return root;
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    insert(5);

    printf("Heap Output: ");
    while (size > 0)
        printf("%d ", deleteRoot());

    return 0;
}
