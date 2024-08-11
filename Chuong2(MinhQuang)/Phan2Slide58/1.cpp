#include <stdio.h>
#include <math.h>

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

int ktSNT(int n)
{
	if(n <= 1 || n % 2 == 0) return 0;
	if(n == 2) return 1;
	for(int i = 3; i < sqrt(n); i+=2)
	{
		if (n % i == 0)
		return 0;
	}
	return 1;
}

void demSNT(int a[], int n)
{
	int dem = 0;
	for (int i = 0; i<n; i++)
	{
		if(ktSNT(a[i]))
		{
			dem++;
		}
	}
	printf("\nMang A chua %d so nguyen to!", dem);
}

int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	demSNT(a,n);
}
