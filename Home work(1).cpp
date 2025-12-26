#include <stdio.h>

typedef struct {
    int row, col, val;
} Triple;

int convertToSparse(int mat[][10], int r, int c, Triple s[]) {
    int k = 0;
    s[k++] = (Triple){r, c, 0}; // header

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                s[k++] = (Triple){i, j, mat[i][j]};
                s[0].val++;
            }
        }
    }
    return k;
}

int main() {
    int mat[4][10] = {
        {0,0,3,0},
        {0,4,0,0},
        {5,0,0,0},
        {0,0,0,6}
    };

    Triple sp[20];
    int n = convertToSparse(mat, 4, 4, sp);

    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", sp[i].row, sp[i].col, sp[i].val);

    return 0;
}
