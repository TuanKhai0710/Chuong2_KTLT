#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// Hàm kiểm tra từng chữ số của số có phải số lẻ không
int isOddDigitNumber(int num) {
	// Kiểm tra từng chữ số của số
	while (num > 0) {
		int digit = num % 10;
		if (digit % 2 == 0) {
			return 0; // false
		}
		num /= 10;
	}
	return 1; // true
}

// Hàm lọc các số từ mảng mà từng chữ số đều là số lẻ
void filterOddDigitNumbers(int *a, int size) {
	for (int i = 0; i < size; i++) {
		if (isOddDigitNumber(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
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

	// Lọc và in các số mà từng chữ số đều là số lẻ
	printf("Cac so co tat ca cac chu so la so le: ");
	filterOddDigitNumbers(a, n);

	// Giải phóng bộ nhớ đã cấp phát
	free(a);
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter

	return 0;
}
