#include <stdio.h>
#define MAX_SIZE 100

// Hàm nhập ma trận vuông từ người dùng
void nhapMangVuong_SoNguyen(int a[][100], int &n) {
	do {
		printf("Cho biet kich thuoc cua ma tran vuong (n x n): ");
		scanf_s("%d", &n);
	} while (n <= 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			printf("Gia tri phan tu a[%d,%d]=", i, j);
			scanf_s("%d", &a[i][j]);
		}
}

// Hàm xuất ma trận vuông
void xuatMangVuong_SoNguyen(int a[][100], int n) {
	printf("Ma tran vuong co gia tri sau: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
// Hàm tính tổng các phần tử trên đường chéo phụ
int tongDuongCheoPhu(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i][n - 1 - i];
	}
	return tong;
}
// Hàm tính tổng các phần tử phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int a[][100], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}

int main() {
	int n;
	int a[MAX_SIZE][MAX_SIZE];

	nhapMangVuong_SoNguyen(a, n);
	xuatMangVuong_SoNguyen(a, n);

	int tong = tongDuongCheoPhu(a, n);
	printf("Tong cac phan tu tren duong cheo phu la: %d\n", tong);

	int tong2 = tongPhiaTrenDuongCheoPhu(a, n);
	printf("Tong cac phan tu phia tren duong cheo phu la: %d\n", tong2);

	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
