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

void demX(int a[], int n)
{
	int x = 0;
	int dem = 0;
	printf("Nhap x can dem: ");
	scanf("%d", &x);
	for(int i = 0; i<n; i++)
	{
		if(x == a[i])
		dem++;
	}
	printf("\nKet qua co %d X trong mang A",dem);
}

int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	demX(a,n);
}
