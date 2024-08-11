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

void lietKeDongToanChan(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        bool toanChan = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                toanChan = false;
                break;
            }
        }
        if (toanChan) {
            printf("Dong chua toan chan: %d\n", i);
        }
    }
}



int main() {
    int m, n;
    int a[MAX_M][MAX_N];
    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    xuatMang(a,m,n);
    lietKeDongToanChan(a, m, n);
	return 0;
}

