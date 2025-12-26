#include <stdio.h>

int main() {
    int a[10] = {10,20,30,40};
    int n = 4;

    // Insert
    for(int i=n;i>2;i--)
        a[i]=a[i-1];
    a[2]=99;
    n++;

    // Delete
    for(int i=1;i<n-1;i++)
        a[i]=a[i+1];
    n--;

    for(int i=0;i<n;i++)
        printf("%d ", a[i]);

    return 0;
}
