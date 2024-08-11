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

void lietKeCotTongNhoNhat(int a[MAX_M][MAX_N], int m, int n) {
    int tong[MAX_N] = {0};
    int minTong = 9999;

    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        tong[j] = sum;
        if (sum < minTong) {
            minTong = sum;
        }
    }

    printf("Cac cot co tong nho nhat (%d):\n", minTong);
    for (int j = 0; j < n; j++) {
        if (tong[j] == minTong) {
            printf("Cot la cot tong nho nhat: %d\n", j);
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
    lietKeCotTongNhoNhat(a, m, n);
	return 0;
}

