#include <stdio.h>

#define MAX_PHAN_SO 50

struct PhanSo {
    float tu;
    float mau;
};


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


struct PhanSo tongPhanSo(struct PhanSo ps1, struct PhanSo ps2) 
{
    struct PhanSo tong;
    tong.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    tong.mau = ps1.mau * ps2.mau;
    return tong;
}


struct PhanSo tichPhanSo(struct PhanSo ps1, struct PhanSo ps2) 
{
    struct PhanSo tich;
    tich.tu = ps1.tu * ps2.tu;
    tich.mau = ps1.mau * ps2.mau;
    return tich;
}


void inPhanSo(struct PhanSo ps) 
{
    printf("%.2f / %.2f\n", ps.tu, ps.mau);
}


struct PhanSo tongDanhSachPhanSo(struct PhanSo ds[], int n) 
{
    struct PhanSo tong = ds[0];

    for (int i = 1; i < n; i++) {
        tong = tongPhanSo(tong, ds[i]);
    }

    return tong;
}

struct PhanSo tichDanhSachPhanSo(struct PhanSo ds[], int n) 
{
    struct PhanSo tich = ds[0];

    for (int i = 1; i < n; i++) {
        tich = tichPhanSo(tich, ds[i]);
    }

    return tich;
}

int main() 
{
    struct PhanSo ds[MAX_PHAN_SO];
    int n;

    nhapDanhSachPhanSo(ds, &n);

    struct PhanSo tong = tongDanhSachPhanSo(ds, n);
    struct PhanSo tich = tichDanhSachPhanSo(ds, n);

    printf("Tong cac phan so la: ");
    inPhanSo(tong);

    printf("Tich cac phan so la: ");
    inPhanSo(tich);

    return 0;
}

