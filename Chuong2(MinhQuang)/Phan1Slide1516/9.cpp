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


int ktSoHoanThien(int n) {
    if(n <= 1) 
	return 0; 

    int sum = 1;  

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            sum += i;
            if(i != n / i) {
                sum += n / i;
            }
        }
    }

    return (sum == n);
}

int main() {
    int n;

    printf("Nhap vao so phan tu mang a: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("So phan tu phai lon hon 0\n");
        return 1;
    }

    int a[n];
    nhapMang(a, n);
    xuatMang(a, n);

    printf("Cac so hoan thien trong mang A la: ");
    for(int i = 0; i < n; i++) {
        if(ktSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");

    return 0;
}

