#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//Xuat cac so nguyen to trong a
int kiemTraSoNT(int n) {
	if (n <= 1)
		return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

// Hàm xuất các số nguyên tố trong mảng
void xuatSoNT(int *a, int n) {
	printf("Cac so nguyen to trong mang la: ");
	for (int i = 0; i < n; i++) {
		if (kiemTraSoNT(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
int main() {
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d", &n);

	if (n <= 0) {
		printf("So luong phan tu phai lon hon 0.\n");
		return 1;
	}

	int *a = (int *)malloc(n * sizeof(int));
	if (a == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < n; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
	xuatSoNT(a, n);
	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
