#include <stdio.h>

struct PhanSo
{
	float tu;
	float mau;
};

int nhapXuatPhanSo(struct PhanSo *ps)
{
	printf("Nhap vao tu so: ");
	scanf("%f", &ps->tu);
	
	do
	{
		printf("Nhap vao mau so: ");
		scanf("%f", &ps->mau);
		if(ps->mau == 0)
		{
			printf("Khong duoc nhap mau = 0!\n");
		}
	} while(ps->mau == 0);

	printf("Phan so vua nhap la: %.f/%.f", ps->tu, ps->mau);
}

int main()
{
	struct PhanSo ps;
	nhapXuatPhanSo(&ps);
}
