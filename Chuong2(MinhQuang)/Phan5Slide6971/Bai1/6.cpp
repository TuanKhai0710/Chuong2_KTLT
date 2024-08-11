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


float giaTriPhanSo(struct PhanSo ps) 
{
    return ps.tu / ps.mau;
}


void inPhanSo(struct PhanSo ps) 
{
    printf("%.2f / %.2f\n", ps.tu, ps.mau);
}


void interchangeSort(struct PhanSo ds[], int n) {
    struct PhanSo temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (giaTriPhanSo(ds[i]) > giaTriPhanSo(ds[j])) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void selectionSort(struct PhanSo ds[], int n) 
{
    struct PhanSo temp;
    int minIndex;
    for (int i = 0; i < n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (giaTriPhanSo(ds[j]) < giaTriPhanSo(ds[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = ds[i];
            ds[i] = ds[minIndex];
            ds[minIndex] = temp;
        }
    }
}


int partition(struct PhanSo ds[], int low, int high) 
{
    float pivotValue = giaTriPhanSo(ds[high]);
    int i = low - 1;
    struct PhanSo temp;
    
    for (int j = low; j < high; j++) {
        if (giaTriPhanSo(ds[j]) < pivotValue) {
            i++;
            temp = ds[i];
            ds[i] = ds[j];
            ds[j] = temp;
        }
    }
    temp = ds[i + 1];
    ds[i + 1] = ds[high];
    ds[high] = temp;
    
    return i + 1;
}


void quickSort(struct PhanSo ds[], int low, int high) 
{
    if (low < high) {
        int pi = partition(ds, low, high);
        quickSort(ds, low, pi - 1);
        quickSort(ds, pi + 1, high);
    }
}

void inDanhSachPhanSo(struct PhanSo ds[], int n) 
{
    for (int i = 0; i < n; i++) {
        inPhanSo(ds[i]);
    }
}

int main() 
{
    struct PhanSo ds[MAX_PHAN_SO];
    int n;
    int luachon;

    nhapDanhSachPhanSo(ds, &n);

    printf("\nChon thuat toan sap xep:\n");
    printf("1. Interchange Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Thoat\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &luachon);

    switch (luachon) {
        case 1:
            interchangeSort(ds, n);
            printf("Danh sach sau khi sap xep theo Interchange Sort:\n");
            inDanhSachPhanSo(ds, n);
            break;
        case 2:
            selectionSort(ds, n);
            printf("Danh sach sau khi sap xep theo Selection Sort:\n");
            inDanhSachPhanSo(ds, n);
            break;
        case 3:
            quickSort(ds, 0, n - 1);
            printf("Danh sach sau khi sap xep theo Quick Sort:\n");
            inDanhSachPhanSo(ds, n);
            break;
        case 4:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
    }

    return 0;
}

