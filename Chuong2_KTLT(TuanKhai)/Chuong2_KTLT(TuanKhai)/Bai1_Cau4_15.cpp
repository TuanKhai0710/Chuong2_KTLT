#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// Tim kiem phan tu x bang 2 cach (vi tri/in thong bao) voi giai thuat tim kiem tuyen tinh/ nhi phan
void timKiemTuyenTinh(int a[], int n, int x) {
	int found = 0; // Biến để kiểm tra xem có tìm thấy phần tử hay không
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			printf("Tim thay so %d o vi tri thu %d bang tim kiem tuyen tinh\n", x, i); // Xuất vị trí của x trong a
			found = 1; // Đánh dấu là đã tìm thấy
		}
	}
	if (!found) {
		printf("Khong tim thay so %d\n", x);
	}
}

int timKiemNhiPhan(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid; // Trả về vị trí của x
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1; // Trả về -1 nếu không tìm thấy x
}
int main() {
	int x, n;
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

	timKiemTuyenTinh(a, n, x);

	int index = timKiemNhiPhan(a, n, x);

	if (index != -1) {
		printf("Tim thay so %d o vi tri thu %d bang tim kiem nhi phan\n", x, index);
	}
	else {
		printf("Khong tim thay so %d \n", x);
	}
	// Giải phóng bộ nhớ đã cấp phát
	free(a);

	// Đợi người dùng nhấn phím trước khi thoát
	printf("NNan phim bat ky de thoat...\n");
	getchar(); // Đọc kí tự '\n' còn sót lại trong bộ đệm
	getchar(); // Đợi người dùng nhấn phím

	return 0;
}
