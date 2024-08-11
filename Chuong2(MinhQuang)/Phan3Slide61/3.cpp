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

int ktTangDan(int a[], int n)
{
	if (n <= 1) return 1;
	for(int i = 1; i< n; i++)
	{
		if(a[i] <= a[i - 1])
			{
				return 0;	
			}
	}
	return 1;
}

int ktGiamDan(int a[], int n)
{
	if (n <= 1) return 1;
	for(int i = 1; i< n; i++)
	{
		if(a[i - 1] <= a[i])
			{
				return 0;	
			}
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
	if (ktTangDan(a, n)) 
	{
        printf("\nMang A la mang tang dan.\n");
    } 
	else if (ktGiamDan(a, n)) 
	{
        printf("\nMang A la mang giam dan.\n");
    } 
	else
	{
        printf("\nMang A khong tang khong giam.\n");
    }
}
