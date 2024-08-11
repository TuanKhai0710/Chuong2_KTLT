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


void swap(int x, int y, int a[]) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(i, j, a);
            }
        }
    }
}

void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(i, j, a);
            }
        }
    }
}


void sapXepMaTranTheoDong(int a[MAX_M][MAX_N], int m, int n)
{
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            sapXepTang(a[i], n);
        } else {
            sapXepGiam(a[i], n);
        }
    }
}

int main() {
    int m, n;
    int a[MAX_M][MAX_N];

    printf("Nhap so hang va cot cua mang: ");
    scanf("%d %d", &m, &n);
    nhapMang(a, m, n);
    
    printf("Ma tran ban dau:\n");
    xuatMang(a, m, n);
    
    sapXepMaTranTheoDong(a, m, n);
    printf("Ma tran sau khi sap xep theo dong:\n");
    xuatMang(a, m, n);
    return 0;
}

