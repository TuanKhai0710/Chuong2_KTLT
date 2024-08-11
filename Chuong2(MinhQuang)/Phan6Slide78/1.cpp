#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_M 100
#define MAX_N 100

bool ktSoLe(int number) {
    char str[12];
    sprintf(str, "%d", number);
    char chu_so_dau = str[0];
    return (chu_so_dau == '1' || chu_so_dau == '3' || chu_so_dau == '5' || chu_so_dau == '7' || chu_so_dau == '9');
}

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

int tongSoLe(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ktSoLe(a[i][j])) {
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
    printf("Tong cac phan tu co chu so dau la so le la: %d\n", tongSoLe(a, m, n));
    return 0;
}

