#include <stdio.h>

// Khai báo cấu trúc phân số
typedef struct {
	int TuSo;   // Tử số
	int MauSo;  // Mẫu số
} PhanSo;

// Hàm xuất phân số
void xuatPhanSo(PhanSo frac) {
	// Kiểm tra mẫu số không phải bằng 0
	if (frac.MauSo == 0) {
		printf("Phan so khong hop le (mau so khong the bang 0).\n");
	}
	else {
		printf("%d/%d\n", frac.TuSo, frac.MauSo);  // Đổi chỗ tử số và mẫu số
	}
}

// Hàm tìm ước số chung lớn nhất (ƯCLN) của hai số
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo *frac) {
	if (frac->MauSo == 0) {
		printf("Phan so khong hop le (mau so khong the bang 0).\n");
		return;
	}
	int div = gcd(frac->TuSo, frac->MauSo);
	frac->TuSo /= div;
	frac->MauSo /= div;
	if (frac->MauSo < 0) { // Đảm bảo mẫu số luôn dương
		frac->MauSo = -frac->MauSo;
		frac->TuSo = -frac->TuSo;
	}
}

int main() {
	PhanSo f1, f2;

	// Nhập phân số đầu tiên
	printf("Nhap phan so thu nhat:\n");
	printf("Tu so: ");
	scanf_s("%d", &f1.TuSo);
	printf("Mau so: ");
	scanf_s("%d", &f1.MauSo);

	// Nhập phân số thứ hai
	printf("Nhap phan so thu hai:\n");
	printf("Tu so: ");
	scanf_s("%d", &f2.TuSo);
	printf("Mau so: ");
	scanf_s("%d", &f2.MauSo);

	// Xuất các phân số
	printf("Phan so thu nhat: ");
	xuatPhanSo(f1);

	printf("Phan so thu hai: ");
	xuatPhanSo(f2);

	// Tối giản phân số đầu tiên
	toiGianPhanSo(&f1);

	// Xuất phân số tối giản
	printf("Phan so toi gian: ");
	xuatPhanSo(f1);

	// Đợi người dùng nhấn Enter để kết thúc
	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter

	return 0;
}
