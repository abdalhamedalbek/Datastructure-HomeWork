int insert(int a[], int n, int pos, int val){
    for(int i=n;i>pos;i--)
        a[i]=a[i-1];
    a[pos]=val;
    return n+1;
}

int delete(int a[], int n, int pos){
    for(int i=pos;i<n-1;i++)
        a[i]=a[i+1];
    return n-1;
}

