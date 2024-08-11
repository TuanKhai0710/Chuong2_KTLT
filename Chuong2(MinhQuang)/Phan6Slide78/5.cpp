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
    printf("Mang a:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int tongPhanTuBien(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    
    //Tong hang dau
    for (int j = 0; j < n; j++) {
        tong += a[0][j];
    }
    
    //Tong hang cuoi
    if (m > 1) {
        for (int j = 0; j < n; j++) {
            tong += a[m - 1][j];
        }
    }
    
    // Tong cot dau va cot cuoi
    for (int i = 1; i < m - 1; i++) {
        tong += a[i][0] + a[i][n - 1];
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
    printf("Tong cac phan tu nam o bien la: %d\n", tongPhanTuBien(a, m, n));
    return 0;
}

