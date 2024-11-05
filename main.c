#include <stdio.h>
#include <stdlib.h>

int **nhap_ma_tran(int row, int col) {
    int **ma_tran = malloc(row * sizeof(int *));
    if (ma_tran == NULL) {
        return NULL;
    }
    for (int i = 0; i < row; i++) {
        ma_tran[i] = (int *) malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("mx[%d][%d]: ", i, j);
            scanf("%d", &ma_tran[i][j]);
        }
    }
    return ma_tran;
}
void xuat_ma_tran(int **ma_tran, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", ma_tran[i][j]);
        }
        printf("\n");
    }
}

void free_ma_tran(int **ma_tran,int n) {
    for(int i = 0; i < n; i++) {
        free(ma_tran[i]);
    }
}

int coDoiXungTam(int **ma_tran, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (ma_tran[i][j] != ma_tran[row-1-i][col-1-j]) {
                return 0;
            }
        }
    }
    return 1;
}
int main(void) {
    int row, col;
    printf("So cot:\n");
    scanf("%d", &row);
    printf("So hang:\n");
    scanf("%d", &col);
    int **ma_tran = nhap_ma_tran(row, col);
    xuat_ma_tran(ma_tran, row, col);
    printf("Ma tran co doi xung qua tam: ");
    int rs = coDoiXungTam(ma_tran, row, col);
    if (rs != 1) {
        printf("Khong");
    }else printf("Co");
    free_ma_tran(ma_tran, row);
    return 0;
}
