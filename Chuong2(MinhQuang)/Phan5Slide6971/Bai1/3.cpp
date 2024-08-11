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

void inDanhSachPhanSo(struct PhanSo ds[], int n) 
{
    printf("Danh sach cac phan so vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan so %d: %.f / %.f\n", i + 1, ds[i].tu, ds[i].mau);
    }
}

float doiRaGiaTri(struct PhanSo ps) //Dùng de doi ra gia tri thap phan de so sanh max
{
    return ps.tu / ps.mau;
}

float phanSoMax(struct PhanSo ds[], int n, struct PhanSo *max)
{
	if (n<=0) 
	{
		printf("Danh sach rong!");
	}
		*max = ds[0];
		for (int i = 1; i<n; i++)
		{
			if (doiRaGiaTri(ds[i]) > doiRaGiaTri(*max))
				*max = ds[i];
		}
}

float phanSoMin(struct PhanSo ds[], int n, struct PhanSo *min)
{
	if (n<=0)
		return 0;
	*min = ds[0];
	for (int i = 1; i<n; i++)
	{
		if (doiRaGiaTri(ds[i]) < doiRaGiaTri(*min))
			*min = ds[i];
	}
}

void inMaxMin(struct PhanSo ps) {
    printf("%.f / %.f\n", ps.tu, ps.mau);
}

int main() {
    struct PhanSo ds[MAX_PHAN_SO];
    struct PhanSo max, min;
    int n;
    nhapDanhSachPhanSo(ds, &n);
    inDanhSachPhanSo(ds, n);
    phanSoMax(ds,n,&max);
    printf("Phan so lon nhat la: ");
    inMaxMin(max);
    printf("\n");
    phanSoMin(ds,n,&min);
    printf("Phan so nho nhat la: ");
    inMaxMin(min);

    return 0;
}

