#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

void nhapMang(int a[MAX_M][MAX_N], int m, int n) {
    printf("Nhap cac phan tu cua mang (%d hang, %d cot):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void xuatMang(int a[MAX_M][MAX_N], int m, int n) {
    printf("Mang a:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tinhTongDuongCheoChinh(int a[MAX_M][MAX_N], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

int main() {
    int m, n;
    int a[MAX_M][MAX_N];

    printf("Nhap so hang va cot cua ma tran vuong: ");
    scanf("%d %d", &m, &n);


    if (m != n) {
        printf("Ma tran phai la ma tran vuong de tinh tong duong cheo chinh.\n");
        return 1;
    }

    nhapMang(a, m, n);
    
    printf("Ma tran ban dau:\n");
    xuatMang(a, m, n);


    int tong = tinhTongDuongCheoChinh(a, n);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tong);

    return 0;
}

