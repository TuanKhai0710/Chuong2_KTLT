#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//Dem tren a co bao nhieu phan tu lon hon x 
int main() {
	int x, n;
	int dem = 0;
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

	printf("Nhap x: ");
	scanf_s("%d", &x);

	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			dem++;
		}
	}
	printf("Co %d phan tu lon hon %d\n", dem, x);
	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
