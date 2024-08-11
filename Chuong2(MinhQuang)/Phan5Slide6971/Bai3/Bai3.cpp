#include <stdio.h>
#include <string.h>

#define MAX_MON_HOC 10
#define MAX_SINH_VIEN 100

struct MonHoc {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
};


struct SinhVien {
    char maSo[15];
    char hoTen[50];
    struct MonHoc monHoc[MAX_MON_HOC];
    int soMonHoc; 
    float diemTrungBinh; 


    void tinhDiemTrungBinh() {
        float tongDiem = 0;
        int tongTinChi = 0;
        for (int i = 0; i < soMonHoc; i++) {
            tongDiem += monHoc[i].diem * monHoc[i].soTinChi;
            tongTinChi += monHoc[i].soTinChi;
        }
        diemTrungBinh = (tongTinChi > 0) ? (tongDiem / tongTinChi) : 0;
    }
};

// Hàm nh?p thông tin m?t môn h?c
void nhapMonHoc(struct MonHoc *mon) {
    printf("Nhap ma mon: ");
    scanf("%s", mon->maMon);
    printf("Nhap ten mon: ");
    scanf(" %[^\n]", mon->tenMon);
    printf("Nhap so tin chi: ");
    scanf("%d", &mon->soTinChi);
    printf("Nhap diem: ");
    scanf("%f", &mon->diem);
}


void nhapSinhVien(struct SinhVien *sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%s", sv->maSo);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]", sv->hoTen);

    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->soMonHoc);
    
    for (int i = 0; i < sv->soMonHoc; i++) {
        printf("Nhap thong tin mon hoc thu %d:\n", i + 1);
        nhapMonHoc(&sv->monHoc[i]);
    }

    sv->tinhDiemTrungBinh();
}


void xuatMonHoc(struct MonHoc mon) {
    printf("Ma mon: %s\n", mon.maMon);
    printf("Ten mon: %s\n", mon.tenMon);
    printf("So tin chi: %d\n", mon.soTinChi);
    printf("Diem: %.2f\n", mon.diem);
}


void xuatSinhVien(struct SinhVien sv) {
    printf("Ma so sinh vien: %s\n", sv.maSo);
    printf("Ho ten: %s\n", sv.hoTen);
    printf("Diem trung binh: %.2f\n", sv.diemTrungBinh);
    for (int i = 0; i < sv.soMonHoc; i++) {
        printf("Thong tin mon hoc thu %d:\n", i + 1);
        xuatMonHoc(sv.monHoc[i]);
    }
}


struct SinhVien* timSinhVien(struct SinhVien ds[], int n, const char *maSo) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSo, maSo) == 0) {
            return &ds[i];
        }
    }
    return NULL;
}


struct SinhVien* timSinhVienDiemCaoNhat(struct SinhVien ds[], int n) {
    if (n == 0) return NULL;
    struct SinhVien *maxSV = &ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTrungBinh > maxSV->diemTrungBinh) {
            maxSV = &ds[i];
        }
    }
    return maxSV;
}


void themSinhVien(struct SinhVien ds[], int *n, struct SinhVien sv) {
    if (*n < MAX_SINH_VIEN) {
        ds[*n] = sv;
        (*n)++;
    } else {
        printf("Danh sach sinh vien da day.\n");
    }
}


void xoaSinhVien(struct SinhVien ds[], int *n, const char *maSo) {
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(ds[i].maSo, maSo) == 0) {
            break;
        }
    }
    if (i < *n) {
        for (int j = i; j < *n - 1; j++) {
            ds[j] = ds[j + 1];
        }
        (*n)--;
    } else {
        printf("Sinh vien voi ma so %s khong ton tai.\n", maSo);
    }
}


void sapXepSinhVien(struct SinhVien ds[], int n, int tangDan) {
    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && ds[i].diemTrungBinh > ds[j].diemTrungBinh) ||
                (!tangDan && ds[i].diemTrungBinh < ds[j].diemTrungBinh)) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


void xepLoaiHocTap(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %s: ", ds[i].hoTen);
        if (ds[i].diemTrungBinh >= 8) {
            printf("Xuat sac\n");
        } else if (ds[i].diemTrungBinh >= 7) {
            printf("Gioi\n");
        } else if (ds[i].diemTrungBinh >= 5) {
            printf("Kha\n");
        } else if (ds[i].diemTrungBinh >= 3) {
            printf("Trung binh\n");
        } else {
            printf("Yeu\n");
        }
    }
}


void thongKeMonHoc(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        int soMonRong = 0;
        for (int j = 0; j < ds[i].soMonHoc; j++) {
            if (ds[i].monHoc[j].diem < 5) {
                soMonRong++;
            }
        }
        printf("Sinh vien %s da rot %d mon hoc.\n", ds[i].hoTen, soMonRong);
    }
}


void inDanhSachSinhVien(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuatSinhVien(ds[i]);
        printf("\n");
    }
}


void nhapDanhSachSinhVien(struct SinhVien ds[], int *n) {
    int soSinhVien;
    printf("Nhap so sinh vien: ");
    scanf("%d", &soSinhVien);
    for (int i = 0; i < soSinhVien; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&ds[*n]);
        (*n)++;
    }
}

int main() {
    struct SinhVien ds[MAX_SINH_VIEN];
    int n = 0;
    int luaChon;

    do {
        printf("MENU:\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo ma so\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien\n");
        printf("6. Xoa sinh vien\n");
        printf("7. Sap xep danh sach sinh vien\n");
        printf("8. Xep loai hoc tap\n");
        printf("9. Thong ke so mon rot\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapDanhSachSinhVien(ds, &n);
                break;
            case 2:
                inDanhSachSinhVien(ds, n);
                break;
            case 3: {
                char maSo[15];
                printf("Nhap ma so sinh vien: ");
                scanf("%s", maSo);
                struct SinhVien* sv = timSinhVien(ds, n, maSo);
                if (sv) {
                    xuatSinhVien(*sv);
                } else {
                    printf("Khong tim thay sinh vien voi ma so %s.\n", maSo);
                }
                break;
            }
            case 4: {
                struct SinhVien* sv = timSinhVienDiemCaoNhat(ds, n);
                if (sv) {
                    xuatSinhVien(*sv);
                } else {
                    printf("Danh sach sinh vien rong.\n");
                }
                break;
            }
            case 5: {
                struct SinhVien sv;
                printf("Nhap thong tin sinh vien:\n");
                nhapSinhVien(&sv);
                themSinhVien(ds, &n, sv);
                break;
            }
            case 6: {
                char maSo[15];
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%s", maSo);
                xoaSinhVien(ds, &n, maSo);
                break;
            }
            case 7: {
                int sapXepTangDan;
                printf("Sap xep tang dan (1) hay giam dan (0)? ");
                scanf("%d", &sapXepTangDan);
                sapXepSinhVien(ds, n, sapXepTangDan);
                break;
            }
            case 8:
                xepLoaiHocTap(ds, n);
                break;
            case 9:
                thongKeMonHoc(ds, n);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (luaChon != 0);

    return 0;
}

