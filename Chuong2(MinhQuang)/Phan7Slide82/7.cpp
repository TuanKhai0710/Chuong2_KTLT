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

void timPhanTuLonNhatTrongCot(int a[MAX_M][MAX_N], int m, int n, int k) {
    if (k < 0 || k >= n) {
        printf("Chi so cot khong hop le.\n");
        return;
    }

    int max = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] > max) {
            max = a[i][k];
        }
    }
    printf("Phan tu lon nhat trong cot %d: %d\n", k, max);
}

void timPhanTuNhoNhatTrongCot(int a[MAX_M][MAX_N], int m, int n, int k) {
    if (k < 0 || k >= n) {
        printf("Chi so cot khong hop le.\n");
        return;
    }

    int min = a[0][k];
    for (int i = 1; i < m; i++) {
        if (a[i][k] < min) {
            min = a[i][k];
        }
    }
    printf("Phan tu nho nhat trong cot %d: %d\n", k, min);
}




int main() {
    int m, n;
    int a[MAX_M][MAX_N];
    int k;
    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    xuatMang(a,m,n);
    printf("Nhap cot k: ");
    scanf("%d", &k);
    timPhanTuLonNhatTrongCot(a, m, n, k);
    timPhanTuNhoNhatTrongCot(a, m, n, k);	
	return 0;
}

