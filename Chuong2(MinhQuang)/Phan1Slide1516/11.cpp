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

void xuatVTChan(int a[], int n)
{
	printf("\nCac phan tu vi tri chan trong A la = ");
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		printf("%d ", a[i]);
	}
}

void xuatVTLe(int a[], int n)
{
	printf("\nCac phan tu vi tri le trong A la = ");
	for(int i = 0; i < n; i++)
	{
		if(i % 2 != 0)
		printf("%d ", a[i]);
	}
}

int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	xuatVTChan(a,n);
	xuatVTLe(a,n);
}
