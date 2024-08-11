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

void timSoNguyenToNhoNhat(int a[MAX_M][MAX_N], int m, int n) {
    int min = 9999;
    bool flag = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ktSNT(a[i][j])) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    flag = true;
                }
            }
        }
    }

    if (flag) {
        printf("So nguyen to nho nhat la: %d\n", min);
    } else {
        printf("Khong tim thay so nguyen to trong ma tran.\n");
    }
}




int main() {
    int m, n;
    int a[MAX_M][MAX_N];
    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    xuatMang(a,m,n);
    timSoNguyenToNhoNhat(a, m, n);
	return 0;
}

