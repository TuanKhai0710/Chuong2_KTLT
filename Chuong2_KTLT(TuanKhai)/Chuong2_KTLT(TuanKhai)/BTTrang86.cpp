#include <stdio.h>
#define MAX_SIZE 100
void nhapMang2C_SoNguyen(int a[][100], int &m, int &n)
{
	do {
		printf("Cho biet so dong cua ma tran: ");
		scanf_s("%d", &m);
	} while (m <= 0);
	do {
		printf("Cho biet so cot cua ma tran: ");
		scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++){
			printf("Gia tri phan tu a[%d,%d]=", i, j);
			scanf_s("%d", &a[i][j]);
		}
}

void xuatMang2C_SoNguyen(int a[][100], int m, int n)
{
	printf("Mang 2 chieu co gia tri sau: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
// Hàm hoán đổi hai số nguyên
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Hàm sắp xếp cột tăng dần
void sortColumnAscending(int a[][MAX_SIZE], int m, int col) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (a[i][col] > a[j][col]) {
				swap(&a[i][col], &a[j][col]);
			}
		}
	}
}

// Hàm sắp xếp cột giảm dần
void sortColumnDescending(int a[][MAX_SIZE], int m, int col) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (a[i][col] < a[j][col]) {
				swap(&a[i][col], &a[j][col]);
			}
		}
	}
}

// Hàm sắp xếp các cột chẵn tăng dần và các cột lẻ giảm dần
void sortMatrix(int a[][MAX_SIZE], int m, int n) {
	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			sortColumnAscending(a, m, j);
		}
		else {
			sortColumnDescending(a, m, j);
		}
	}
}

int main() {
	int m, n, k, x;
	int a[MAX_SIZE][MAX_SIZE];
	nhapMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);

	sortMatrix(a, m, n);

	printf("Ma tran sau khi sap xep:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
