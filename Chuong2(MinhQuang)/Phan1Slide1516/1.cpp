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


int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
}
