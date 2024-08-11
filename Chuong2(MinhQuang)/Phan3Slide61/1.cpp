#include <stdio.h>
#include <math.h>

void nhapMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("Mang a = ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int ktSNT(int n) {
    if(n <= 1) return 0; 
    if(n == 2) return 1; 
    if(n % 2 == 0) return 0; 
    for(int i = 3; i <= sqrt(n); i += 2) { 
        if(n % i == 0) return 0;
    }
    return 1;
}

void toanMangSNT(int a[], int n) {
    int flag = 1;
    for(int i = 0; i < n; i++) {
        if(!ktSNT(a[i])) {
            flag = 0;
            break; 
        }
    }
    if(flag == 0) {
        printf("\nMang A khong chua toan SNT");
    } else {
        printf("\nMang A chua toan SNT");
    }
}

int main() {
    int n;
    printf("Nhap vao so phan tu mang a: ");
    scanf("%d", &n);
    int a[n];
    nhapMang(a, n);
    xuatMang(a, n);
    toanMangSNT(a, n);
    return 0;
}

