#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// Kiểm tra mảng có toàn là số chẵn không
int kiemTraSoChan(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			return 0; //mang co so le
		}
	}
	return 1; //mang toan chan
}

int main() {
	int n;

	// Nhập số phần tử của mảng
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d", &n);

	if (n <= 0) {
		printf("So luong phan tu phai lon hon 0.\n");
		return 1;
	}

	// Cấp phát bộ nhớ cho mảng
	int *a = (int *)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	// Nhập các phần tử của mảng
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}

	if (kiemTraSoChan(a, n)) {
		printf("Tat ca cac phan tu trong mang deu la so chan.\n");
	}
	else {
		printf("Mang khong co tat ca cac phan tu la so chan.\n");
	}

	// Giải phóng bộ nhớ đã cấp phát
	free(a);
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter

	return 0;
}
