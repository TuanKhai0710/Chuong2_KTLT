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

bool ktSNT(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int demChan(int a[MAX_M][MAX_N], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0)
				dem++;
        }
    }
    return dem;
}

int demLe(int a[MAX_M][MAX_N], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0)
				dem++;
        }
    }
    return dem;
}

int demAm(int a[MAX_M][MAX_N], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0)
				dem++;
        }
    }
    return dem;
}

int demDuong(int a[MAX_M][MAX_N], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] > 0)
				dem++;
        }
    }
    return dem;
}

int demSNT(int a[MAX_M][MAX_N], int m, int n) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ktSNT(a[i][j]))
				dem++;
        }
    }
    return dem;
}

int main() {
    int m, n;
    int a[MAX_M][MAX_N];
    int dem;
    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    xuatMang(a,m,n);
	printf("So luong so chan: %d\n", demChan(a,m,n));
    printf("So luong so le: %d\n", demLe(a,m,n));
    printf("So luong so am: %d\n", demAm(a,m,n));
    printf("So luong so duong: %d\n", demDuong(a,m,n));
    printf("So luong so nguyen to: %d\n", demSNT(a,m,n));
    return 0;
}

