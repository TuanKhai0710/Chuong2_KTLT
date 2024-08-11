#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// Hàm xuất các phần tử ở vị trí chan trong mảng
void xuatPhanTuViTriChan(int *a, int n) {
	printf("Cac phan tu o vi tri chan trong mang la: ");
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

// Hàm xuất các phần tử ở vị trí lẻ trong mảng
void xuatPhanTuViTriLe(int *a, int n) {
	printf("Cac phan tu o vi tri le trong mang la: ");
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0) {
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
	xuatPhanTuViTriChan(a, n);
	xuatPhanTuViTriLe(a, n);
	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
