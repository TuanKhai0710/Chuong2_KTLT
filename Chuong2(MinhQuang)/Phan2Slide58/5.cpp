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

int ktMangXenKeChanLe(int a[], int n)
{
	if (n<2) return 1;
	
	int chan (a[0] % 2 == 0);
	for(int i = 1; i<n; i++)
		{
			int hienTaiChan (a[i] % 2 == 0);
			if(hienTaiChan == chan)
			{
				return 0;
			}
			chan = hienTaiChan;
		}
		return 1;
}

int main()
{
	int n;
	printf("Nhap vao so phan tu mang a: ");
	scanf("%d", &n);
	int a[n];
	nhapMang(a,n);
	xuatMang(a,n);
	if(ktMangXenKeChanLe(a,n))
	{
		printf("\nMang A xen ke chan le!\n");
	}
	else
	{
		printf("Mang A khong xen ke chan le!");
	}
}
