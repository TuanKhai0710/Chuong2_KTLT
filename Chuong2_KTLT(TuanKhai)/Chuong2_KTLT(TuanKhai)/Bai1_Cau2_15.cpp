#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//Tìm max/min của mảng a
int main() {
	int n;
	printf("Nhap so luong phan tu trong mang: ");
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

	int max = a[0];
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	printf("Gia tri lon nhat la: %d\n", max);
	printf("Gia tri nho nhat la: %d\n", min);

	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
