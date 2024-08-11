#include <stdio.h>


void nhapMang(int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("Nhap a[%d]: ",i);
		scanf("%d", &a[i]);	
	}
}

void xuatMang(int a[], int n)
{
	printf("Mang a = ");
	for(int i = 0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}


void demChan(int a[], int n)
{
	int dem = 0;
	for(int i = 0; i<n; i++)
	{
		if (a[i] % 2 == 0)
		dem++;
	}
	printf("\nSo phan tu chan trong a la: %d", dem);
}

void demLe(int a[], int n)
{
	int dem = 0;
	for(int i = 0; i<n; i++)
	{
		if (a[i] % 2 != 0)
		dem++;
	}
	printf("\nSo phan tu le trong a la: %d", dem);
}

int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	demChan(a,n);
	demLe(a,n);
}
