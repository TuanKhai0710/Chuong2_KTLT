#include <stdio.h>
#define MAX_SIZE 100
void nhapMang2C_SoNguyen(int a[][100], int &m, int &n)
{
	do {
		printf("Cho biet so dong cua ma tran: ");
		scanf_s("%d", &m);
	} while (m <= 0);
	do {
		printf("Cho biet so cot cua ma tran: ");
		scanf_s("%d", &n);
	} while (n <= 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++){
			printf("Gia tri phan tu a[%d,%d]=", i, j);
			scanf_s("%d", &a[i][j]);
		}
}

void xuatMang2C_SoNguyen(int a[][100], int m, int n)
{
	printf("Mang 2 chieu co gia tri sau: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}
// Hàm kiểm tra số hoàn thiện
int soHoanThien(int num) {
	if (num < 2) return 0; // Số hoàn thiện nhỏ nhất là 6, nên số nhỏ hơn 2 không phải là số hoàn thiện
	int sum = 1;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum == num;
}
// Hàm đếm số lượng số hoàn thiện trong một dòng
int demSoHoanThien(int a[][100], int row, int n) {
	int count = 0;
	for (int j = 0; j < n; j++) {
		if (soHoanThien(a[row][j])) {
			count++;
		}
	}
	return count;
}
// Hàm liệt kê các dòng có nhiều số hoàn thiện nhất
void lietKeDongNhieuSoHoanThienNhat(int a[][100], int m, int n) {
	int maxCount = 0;
	int perfectCounts[100] = { 0 }; // Mảng lưu số lượng số hoàn thiện của từng dòng

	// Tính số lượng số hoàn thiện của từng dòng và tìm giá trị lớn nhất
	for (int i = 0; i < m; i++) {
		perfectCounts[i] = demSoHoanThien(a, i, n);
		if (perfectCounts[i] > maxCount) {
			maxCount = perfectCounts[i];
		}
	}

	// Liệt kê các dòng có số lượng số hoàn thiện bằng giá trị lớn nhất
	printf("Cac dong co nhieu so hoan thien nhat:\n");
	for (int i = 0; i < m; i++) {
		if (perfectCounts[i] == maxCount) {
			printf("Dong %d\n", i);
		}
	}
}

// Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
void findMostFrequentValue(int a[][MAX_SIZE], int m, int n) {
	int frequency[MAX_SIZE * MAX_SIZE] = { 0 }; // Giả sử giá trị trong ma trận không vượt quá 10000
	int maxFreq = 0, mostFrequentValue = 0;

	// Đếm tần suất xuất hiện của từng giá trị
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			frequency[a[i][j]]++;
			if (frequency[a[i][j]] > maxFreq) {
				maxFreq = frequency[a[i][j]];
				mostFrequentValue = a[i][j];
			}
		}
	}

	// Tìm giá trị có tần suất xuất hiện nhiều nhất
	printf("Gia tri xuat hien nhieu nhat trong ma tran la: %d\n", mostFrequentValue);
	printf("So lan xuat hien: %d\n", maxFreq);
}

// Hàm tìm phần tử lớn nhất trong dòng k
int timMaxDongk(int a[][MAX_SIZE], int n, int k) {
	int max = a[0][0];
	for (int j = 0; j < n; j++) {
		if (a[k][j] > max) {
			max = a[k][j];
		}
	}
	return max;
}

// Hàm tìm phần tử nhỏ nhất trong dòng k
int timMinDongk(int a[][MAX_SIZE], int n, int k) {
	int min = a[0][0];
	for (int j = 0; j < n; j++) {
		if (a[k][j] < min) {
			min = a[k][j];
		}
	}
	return min;
}

int main() {
	int m, n, k, x;
	int a[MAX_SIZE][MAX_SIZE];
	nhapMang2C_SoNguyen(a, m, n);
	xuatMang2C_SoNguyen(a, m, n);


	lietKeDongNhieuSoHoanThienNhat(a, m, n);
	findMostFrequentValue(a, m, n);

	printf("Nhap chi so dong k (0 den %d): ", m - 1);
	scanf_s("%d", &k);

	if (k >= 0 && k < m) {
		int maxInRow = timMaxDongk(a, n, k);
		int minInRow = timMinDongk(a, n, k);
		printf("Phan tu lon nhat trong dong %d la: %d\n", k, maxInRow);
		printf("Phan tu nho nhat trong dong %d la: %d\n", k, minInRow);
	}
	else {
		printf("Chỉ số dòng không hợp lệ.\n");
	}
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
