#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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
    printf("Mang a:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tongTuyetDoi(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int main() {
    int m, n;
    int a[MAX_M][MAX_N];
    
    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    xuatMang(a,m,n);
    printf("Tong cac phan tu lon hon gia tri tuyet doi la: %d\n", tongTuyetDoi(a, m, n));
    return 0;
}

