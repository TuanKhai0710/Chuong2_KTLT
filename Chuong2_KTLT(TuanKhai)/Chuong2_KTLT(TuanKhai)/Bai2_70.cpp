#include <stdio.h>
#include <string.h>

#define MAX_SINH_VIEN 100 // Giới hạn số lượng sinh viên tối đa

typedef struct {
	int soThuTu;
	char maSV[20];
	char hoTen[50];
	float diemTieuLuan;
	float diemThiKetThuc;
	float diemTongKet;
	float diemHe4;
} SinhVien;

// Hàm nhập thông tin sinh viên
void nhapDanhSachSinhVien(SinhVien *danhSach, int soLuong) {
	for (int i = 0; i < soLuong; i++) {
		printf("Nhap thong tin sinh vien %d:\n", i + 1);
		danhSach[i].soThuTu = i + 1;
		printf("  Ma sinh vien: ");
		scanf_s("%19s", danhSach[i].maSV, (unsigned)sizeof(danhSach[i].maSV));
		printf("  Ho ten sinh vien: ");
		scanf_s(" %[^\n]", danhSach[i].hoTen, (unsigned)sizeof(danhSach[i].hoTen));
		printf("  Diem tieu luan: ");
		scanf_s("%f", &danhSach[i].diemTieuLuan);
		printf("  Diem thi ket thuc: ");
		scanf_s("%f", &danhSach[i].diemThiKetThuc);

		// Tính điểm tổng kết
		danhSach[i].diemTongKet = 0.3 * danhSach[i].diemTieuLuan + 0.7 * danhSach[i].diemThiKetThuc;

		// Chuyển đổi điểm sang hệ 4
		danhSach[i].diemHe4 = (danhSach[i].diemTongKet / 10) * 4;
	}
}

// Hàm xuất thông tin sinh viên
void xuatDanhSachSinhVien(SinhVien *danhSach, int soLuong) {
	for (int i = 0; i < soLuong; i++) {
		printf("\nSinh vien %d:\n", i + 1);
		printf("  Ma sinh vien: %s\n", danhSach[i].maSV);
		printf("  Ho ten: %s\n", danhSach[i].hoTen);
		printf("  Diem tieu luan: %.2f\n", danhSach[i].diemTieuLuan);
		printf("  Diem thi ket thuc: %.2f\n", danhSach[i].diemThiKetThuc);
		printf("  Diem tong ket: %.2f\n", danhSach[i].diemTongKet);
		printf("  Diem he 4: %.2f\n", danhSach[i].diemHe4);
	}
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất và thấp nhất
void timDiemCaoThapNhat(SinhVien *danhSach, int soLuong) {
	if (soLuong <= 0) return;

	SinhVien *svCaoNhat = &danhSach[0];
	SinhVien *svThapNhat = &danhSach[0];

	for (int i = 1; i < soLuong; i++) {
		if (danhSach[i].diemTongKet > svCaoNhat->diemTongKet) {
			svCaoNhat = &danhSach[i];
		}
		if (danhSach[i].diemTongKet < svThapNhat->diemTongKet) {
			svThapNhat = &danhSach[i];
		}
	}

	printf("\nSinh vien co diem tong ket cao nhat:\n");
	printf("  Ma sinh vien: %s\n", svCaoNhat->maSV);
	printf("  Ho ten: %s\n", svCaoNhat->hoTen);
	printf("  Diem tong ket: %.2f\n", svCaoNhat->diemTongKet);

	printf("\nSinh vien co diem tong ket thap nhat:\n");
	printf("  Ma sinh vien: %s\n", svThapNhat->maSV);
	printf("  Ho ten: %s\n", svThapNhat->hoTen);
	printf("  Diem tong ket: %.2f\n", svThapNhat->diemTongKet);
}

// Hàm đếm số sinh viên đạt và không đạt
void demSinhVienDatKhongDat(SinhVien *danhSach, int soLuong) {
	int dat = 0;
	int khongDat = 0;
	for (int i = 0; i < soLuong; i++) {
		if (danhSach[i].diemTongKet >= 5.0) {
			dat++;
		}
		else {
			khongDat++;
		}
	}
	printf("\nSo sinh vien dat: %d\n", dat);
	printf("So sinh vien khong dat: %d\n", khongDat);
}

// Hàm sắp xếp sinh viên theo điểm tổng kết (tăng dần hoặc giảm dần)
void sapXepSinhVien(SinhVien *danhSach, int soLuong, int tangDan) {
	for (int i = 0; i < soLuong - 1; i++) {
		for (int j = i + 1; j < soLuong; j++) {
			if ((tangDan && danhSach[i].diemTongKet > danhSach[j].diemTongKet) ||
				(!tangDan && danhSach[i].diemTongKet < danhSach[j].diemTongKet)) {
				SinhVien temp = danhSach[i];
				danhSach[i] = danhSach[j];
				danhSach[j] = temp;
			}
		}
	}
}

// Hàm tính điểm trung bình của tất cả các sinh viên
float tinhDiemTrungBinh(SinhVien *danhSach, int soLuong) {
	float tongDiem = 0;
	for (int i = 0; i < soLuong; i++) {
		tongDiem += danhSach[i].diemTongKet;
	}
	return soLuong > 0 ? tongDiem / soLuong : 0;
}

int main() {
	SinhVien danhSach[MAX_SINH_VIEN];
	int n;

	// Nhập số lượng sinh viên
	printf("Nhap so luong sinh vien: ");
	scanf_s("%d", &n);

	if (n <= 0 || n > MAX_SINH_VIEN) {
		printf("So luong sinh vien khong hop le. Phai tu 1 den %d.\n", MAX_SINH_VIEN);
		return 1;
	}

	// Nhập thông tin sinh viên
	nhapDanhSachSinhVien(danhSach, n);

	// Xuất thông tin sinh viên
	xuatDanhSachSinhVien(danhSach, n);

	// Tìm sinh viên có điểm tổng kết cao nhất và thấp nhất
	timDiemCaoThapNhat(danhSach, n);

	// Đếm số sinh viên đạt và không đạt
	demSinhVienDatKhongDat(danhSach, n);

	// Sắp xếp sinh viên theo điểm tổng kết
	char luaChon;
	printf("\nBan muon sap xep danh sach theo diem tong ket (tang dan: y / giam dan: n)? ");
	scanf_s(" %c", &luaChon);
	int tangDan = (luaChon == 'y' || luaChon == 'Y') ? 1 : 0;
	sapXepSinhVien(danhSach, n, tangDan);

	// Xuất danh sách sau khi sắp xếp
	printf("\nDanh sach sinh vien sau khi sap xep:\n");
	xuatDanhSachSinhVien(danhSach, n);

	// Tính điểm trung bình của tất cả các sinh viên
	float diemTrungBinh = tinhDiemTrungBinh(danhSach, n);
	printf("\nDiem trung binh cua tat ca sinh vien: %.2f\n", diemTrungBinh);

	printf("Nhan Enter de ket thuc chuong trinh...\n");
	getchar(); // Đọc ký tự Enter còn lại từ buffer
	getchar(); // Chờ người dùng nhấn Enter 
	return 0;
}
