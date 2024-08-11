#include <stdio.h>

#define MAX_PHAN_SO 50

struct PhanSo {
    float tu;
    float mau;
};

// Ham nghich dao cua phan so
struct PhanSo nghichDaoPhanSo(struct PhanSo ps) {
    struct PhanSo nghichDao;
    nghichDao.tu = ps.mau;
    nghichDao.mau = ps.tu;
    return nghichDao;
}

void nhapPhanSo(struct PhanSo *ps) 
{
    printf("Nhap vao tu so: ");
    scanf("%f", &ps->tu);

    do {
        printf("Nhap vao mau so: ");
        scanf("%f", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void nhapDanhSachPhanSo(struct PhanSo ds[], int *n) 
{
    do {
        printf("Nhap so luong phan so (tu 1 den %d): ", MAX_PHAN_SO);
        scanf("%d", n);
        if (*n < 1 || *n > MAX_PHAN_SO) {
            printf("So luong phan so khong hop le. Vui long nhap lai.\n");
        }
    } while (*n < 1 || *n > MAX_PHAN_SO);

    for (int i = 0; i < *n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&ds[i]);
    }
}

void inPhanSo(struct PhanSo ps) {
    printf("%.f / %.f\n", ps.tu, ps.mau);
}

void inDanhSachNghichDao(struct PhanSo ds[], int n) {
    printf("Danh sach nghich dao cua cac phan so vua nhap:\n");
    for (int i = 0; i < n; i++) {
        struct PhanSo nghichDao = nghichDaoPhanSo(ds[i]);
        inPhanSo(nghichDao);
    }
}


int main() {
    struct PhanSo ds[MAX_PHAN_SO];
    int n;
    nhapDanhSachPhanSo(ds, &n);
    inDanhSachNghichDao(ds, n);

    return 0;
}

