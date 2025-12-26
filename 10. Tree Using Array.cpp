#include <stdio.h>

int tree[15] = {10,5,20,3,7,-1,30};

void preorder(int i) {
    if(i>=15 || tree[i]==-1) return;
    printf("%d ", tree[i]);
    preorder(2*i+1);
    preorder(2*i+2);
}

int main() {
    preorder(0);
    return 0;
}

