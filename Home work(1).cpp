#include <stdio.h>

typedef struct {
    int row, col, value;
} Sparse;

int main() {
    int matrix[4][4] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {5, 0, 0, 0},
        {0, 0, 0, 6}
    };

    Sparse s[20];
    int k = 1;

    s[0].row = 4;
    s[0].col = 4;
    s[0].value = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].value = matrix[i][j];
                k++;
                s[0].value++;
            }
        }
    }

    printf("Row Col Value\n");
    for (int i = 0; i < k; i++) {
        printf("%d   %d   %d\n", s[i].row, s[i].col, s[i].value);
    }

    return 0;
}
