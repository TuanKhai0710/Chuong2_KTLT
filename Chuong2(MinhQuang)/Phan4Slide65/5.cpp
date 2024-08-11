#include <stdio.h>

struct PhanSo
{
    float tu;
    float mau;
};

void nhapPhanSo(struct PhanSo *ps)
{
    printf("Nhap vao tu so: ");
    scanf("%f", &ps->tu);
    do
    {
        printf("Nhap vao mau so: ");
        scanf("%f", &ps->mau);
        if (ps->mau == 0)
        {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void phepTinh(struct PhanSo ps1, struct PhanSo ps2)
{

    float tongTu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    float tongMau = ps1.mau * ps2.mau;
    printf("Tong: %.f/%.f\n", tongTu, tongMau);

    float hieuTu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    float hieuMau = ps1.mau * ps2.mau;
    printf("Hieu: %.f/%.f\n", hieuTu, hieuMau);

    float tichTu = ps1.tu * ps2.tu;
    float tichMau = ps1.mau * ps2.mau;
    printf("Tich: %.f/%.f\n", tichTu, tichMau);

    if (ps2.tu == 0)
    {
        printf("Khong the chia cho phan so co tu so = 0\n");
    }
    else
    {
        float thuongTu = ps1.tu * ps2.mau;
        float thuongMau = ps1.mau * ps2.tu;
        printf("Thuong: %.f/%.f\n", thuongTu, thuongMau);
    }
}

int main()
{
    struct PhanSo ps1, ps2;

    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);

    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    phepTinh(ps1, ps2);

    return 0;
}

