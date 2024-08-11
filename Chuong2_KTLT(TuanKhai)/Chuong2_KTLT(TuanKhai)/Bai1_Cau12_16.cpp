#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void merge_sorted_arrays(int *a, int *b, int m, int *c, int n) {
	int i = 0, j = 0, k = 0;

	// Hợp nhất hai mảng b và c vào mảng a
	while (i < m && j < n) {
		if (b[i] < c[j]) {
			a[k++] = b[i++];
		}
		else {
			a[k++] = c[j++];
		}
	}

	// Nếu còn phần tử trong mảng b
	while (i < m) {
		a[k++] = b[i++];
	}

	// Nếu còn phần tử trong mảng c
	while (j < n) {
		a[k++] = c[j++];
	}
}

int main() {
	int m, n;

	// Nhập số phần tử của dãy b
	printf("Nhap so phan tu cua day b: ");
	scanf_s("%d", &m);

	if (m <= 0) {
		printf("So luong phan tu phai lon hon 0.\n");
		return 1;
	}

	// Cấp phát bộ nhớ cho dãy b
	int *b = (int *)malloc(m * sizeof(int));
	if (b == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}

	// Nhập các phần tử của dãy b
	printf("Nhap cac phan tu cua day b (tang dan):\n");
	for (int i = 0; i < m; i++) {
		printf("b[%d] = ", i);
		scanf_s("%d", &b[i]);
	}

	// Nhập số phần tử của dãy c
	printf("Nhap so phan tu cua day c: ");
	scanf_s("%d", &n);

	if (n <= 0) {
		printf("So luong phan tu phai lon hon 0.\n");
		free(b);
		return 1;
	}

	// Cấp phát bộ nhớ cho dãy c
	int *c = (int *)malloc(n * sizeof(int));
	if (c == NULL) {
		printf("Khong the cap phat bo nho.\n");
		free(b);
		return 1;
	}

	// Nhập các phần tử của dãy c
	printf("Nhap cac phan tu cua day c (tang dan):\n");
	for (int i = 0; i < n; i++) {
		printf("c[%d] = ", i);
		scanf_s("%d", &c[i]);
	}

	// Cấp phát bộ nhớ cho dãy a
	int *a = (int *)malloc((m + n) * sizeof(int));
	if (a == NULL) {
		printf("Khong the cap phat bo nho.\n");
		free(b);
		free(c);
		return 1;
	}

	// Hợp nhất hai dãy b và c thành dãy a
	merge_sorted_arrays(a, b, m, c, n);

	// In dãy a
	printf("Day a (sau khi hop nhat va sap xep tang dan):\n");
	for (int i = 0; i < m + n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	// Giải phóng bộ nhớ đã cấp phát
	free(b);
	free(c);
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
