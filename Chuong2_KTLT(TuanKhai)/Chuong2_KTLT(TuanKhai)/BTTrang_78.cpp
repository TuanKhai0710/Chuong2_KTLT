#include <stdio.h>

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
// Hàm kiểm tra số hoàn thiện
int soHoanThien(int num) {
	if (num < 2) return 0; // Số hoàn thiện nhỏ nhất là 6, nên số nhỏ hơn 2 không phải là số hoàn thiện
	int sum = 1;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum == num;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[][100], int m, int n) {
	printf("Cac so hoan thien trong ma tran la: ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (soHoanThien(a[i][j])) {
				printf("%d ", a[i][j]);
			}
		}
	}
	printf("\n");
}
//Ham tinh tong gia tri tren dong k cua ma tran
int tongDong(int a[][100], int n, int k) {
	int sum = 0;
	for (int j = 0; j < n; j++) {
		sum += a[k][j];
	}
	return sum;
}
// Hàm đếm tần suất xuất hiện của giá trị x trong ma trận
int demSoLanXuatHien(int a[][100], int m, int n, int x) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == x) {
				count++;
			}
		}
	}
	return count;
}
int main() {
	int m, n, k, x;
	int a[100][100];
	nhapMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);

	lietKeSoHoanThien(a, m, n);

	printf("Nhap chi so dong k (0 den %d): ", m - 1);
	scanf_s("%d", &k);

	if (k >= 0 && k < m) {
		int sum = tongDong(a, n, k);
		printf("Tong cac gia tri tren dong %d la: %d\n", k, sum);
	}
	else {
		printf("Chi so dong khong hop le.\n");
	}

	printf("Nhap gia tri can dem tan suat xuat hien trong ma tran: ");
	scanf_s("%d", &x);

	int count = demSoLanXuatHien(a, m, n, x);
	printf("Gia tri %d xuat hien %d lan trong ma tran.\n", x, count);
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
