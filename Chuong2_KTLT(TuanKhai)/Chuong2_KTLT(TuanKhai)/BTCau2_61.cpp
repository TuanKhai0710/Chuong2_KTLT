#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// Hàm kiểm tra xem mảng có đối xứng hay không
int kiemTraDoiXung(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1]) {
			return 0; // false, mảng không đối xứng
		}
	}
	return 1; // true, mảng đối xứng
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

	// Kiểm tra và in kết quả xem mảng có đối xứng hay không
	if (kiemTraDoiXung(a, n)) {
		printf("Mang doi xung.\n");
	}
	else {
		printf("Mang khong doi xung.\n");
	}

	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Chờ người dùng nhấn Enter trước khi kết thúc
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter

	return 0;
}
