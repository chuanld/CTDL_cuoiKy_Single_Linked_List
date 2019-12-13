#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <iostream>
using namespace std;

typedef struct tagSINHVIEN {
	int Msv;
	char Hoten[35];
	int ngay, thang, nam;
	float CTDL;
	float OOP;
	float TK;
}SINHVIEN, * PSINHVIEN;

typedef struct tagNODE {
	SINHVIEN Data;
	tagNODE* Next;
}NODE, * PNODE;

typedef struct tagLIST {
	NODE* Dau;
	NODE* Cuoi;
}LISTSV, * PLIST;

//Khoi tao NODE
NODE* KhoitaoNode()
{
	NODE* x = (NODE*)malloc(sizeof(NODE));
	if (x == NULL)
	{
		printf_s("\n Bo nho khong du ");
		return 0;
	}
	x->Next = NULL;
	return x;
}

//Khoi tao danh sach LISTSV
void KhoitaoList(LISTSV* x)
{
	x->Dau = NULL;
	x->Cuoi = NULL;
}

//Nhap thong tin sinh vien
void Nhap(NODE* x)
{
	char tg[25];
	int a, d, m, y;
	float t, c;
	printf_s("\nNhap ma so Sinh vien: ");
	scanf_s("%d", &a);
	x->Data.Msv = a;
	fflush(stdin);
	cin.ignore();
	printf_s("Nhap ten Sinh Vien: ");
	cin.getline(tg, 25);
	strcpy_s(x->Data.Hoten, tg);
	fflush(stdin);
	do
	{
		printf_s("Nhap Ngay Sinh: ");
		scanf_s("%d", &d);
		fflush(stdin);
	} while (d > 31 || d < 1);
	x->Data.ngay = d;
	do
	{
		printf_s("Nhap Thang Sinh: ");
		scanf_s("%d", &m);
		fflush(stdin);
	} while (m > 12 || m < 1);
	x->Data.thang = m;
	do
	{
		printf_s("Nhap Nam Sinh: ");
		scanf_s("%d", &y);
		fflush(stdin);
	} while (y > 2020 || y < 1000);
	x->Data.nam = y;
	fflush(stdin);
	do
	{
		printf_s("Nhap Diem CTDL: ");
		scanf_s("%f", &c);
	} while (c < 0 || c > 10);
	x->Data.CTDL = c;
	fflush(stdin);
	do
	{
		printf_s("Nhap Diem OOP: ");
		scanf_s("%f", &t);
	} while (t < 0 || t > 10);
	x->Data.OOP = t;
	x->Data.TK = (x->Data.CTDL + x->Data.OOP) / 2;
	fflush(stdin);
	x->Next = NULL;
}

//in sinh vien
void InSV(NODE* p)
{
	printf_s("\nMa so Sinh vien: %d   ", p->Data.Msv);
	printf_s("\tTen Sinh vien: %s  ", p->Data.Hoten);
	printf_s("\nNgay/ Thang/ Nam sinh: %2d/%2d/%4d   ", p->Data.ngay, p->Data.thang, p->Data.nam);
	printf_s("\nDiem CTDL: %.2f   ", p->Data.CTDL);
	printf_s("\tDiem OOP: %.2f   ", p->Data.OOP);
	printf_s("\tDiem tong ket: %.2f\n\n\n", p->Data.TK);
}

// in danh sach SINHVIEN
void InDanhSach(LISTSV x)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		InSV(p);
		p = p->Next;
	}
}

//Them mot NODE vao Cuoi danh sach
void ThemCuoi(LISTSV* x, NODE* t)
{
	if (x->Dau == NULL)
	{
		x->Dau = t;
	}
	else
	{
		x->Cuoi->Next = t;
	}
	x->Cuoi = t;
}

// Them mot sinh vien vao cuoi danh sach
int NhapSV(LISTSV* x)
{
	NODE* a = KhoitaoNode();
	Nhap(a);
	ThemCuoi(x, a);
	return 0;
}

//Tim kiem theo Ma sinh vien
void TimKiem(LISTSV x, int n)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.Msv == n)
		{
			InSV(p);
		}
		else   printf_s("\n Khong co sinh vien dat tieu chuan can tim\n");
		p = p->Next;
	}
}

//Xoa 1 Sinh Vien bat ki Theo ma Sinh Vien
int XoaSV(LISTSV* x, int n)
{
	NODE* p = x->Dau, * q;
	q = NULL;
	while (p != NULL)
	{
		if (p->Data.Msv == n)
			break;
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		return 0; //không  tim thay
	if (q != NULL)
	{
		x->Cuoi = q;
		q->Next = p->Next;
		delete p; 
	}
	else
	{
		x->Dau = p->Next;
		if (x->Dau == NULL)
			x->Cuoi = NULL;
	}
	return 1;
}

//Giai phong bo nho
void giaiphong(LISTSV* x)
{
	NODE* p = x->Dau;
	NODE* a;
	while (p->Next != NULL)
	{
		a = p;
		p = p->Next;
		free(a);
	}
}

//In cac Sinh Vien xep Loai Gioi
void inSVGioi(LISTSV x)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.TK >= 8)
		{
			InSV(p);
		}
		else printf_s("\n Khong co sinh vien dat tieu chuan can tim\n");
		p = p->Next;
	}
}

//In cac Sinh Vien xep Loai Kha
void inSVKha(LISTSV x)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.TK < 8 && p->Data.TK >= 7)
		{
			InSV(p);
		}
		else printf_s("\n Khong co sinh vien dat tieu chuan can tim\n");
		p = p->Next;
	}
}

//Liet ke so SINHVIEN bi thi Lai

void inSVThilai(LISTSV x)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.CTDL < 5 || p->Data.OOP < 5)
		{
			InSV(p);
		}
		else printf_s("\n Khong co sinh vien dat tieu chuan can tim\n");
		p = p->Next;
	}
}

//Dem so SINHVIEN Hoc Lai
void SVHocLai(LISTSV x)
{
	NODE* p;
	int n = 0;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.CTDL < 5 && p->Data.OOP < 5)
		{
			n++;
		}
		p = p->Next;
	}
	printf_s("\n So Cac sinh vien Phai Hoc Lai : %d\n", n);
}

// Liet ke Sinh vien Sinh vao thang 10
void inSV10(LISTSV x)
{
	NODE* p;
	p = x.Dau;
	while (p != NULL)
	{
		if (p->Data.thang == 10)
		{
			printf_s("\n Cac sinh vien sinh vao thang 10 :");
			InSV(p);
		}
		else printf_s("\n Khong co sinh vien dat tieu chuan can tim\n");
		p = p->Next;
	}
}

//Ham Tao Danh Sach Tuy chon
int Menu()
{
	int a;
	int Ma;
	LISTSV x;
	KhoitaoList(&x);
	do
	{
		printf_s("\n Ban chon 1,2,3,4,5");
		printf_s("\n\nNhap so can chon roi bam enter");
		printf_s("\n\n\n 1 - Nhap danh sach Sinh Vien");
		printf_s("\n 2 - Liet ke danh sach Sinh Vien");
		printf_s("\n 3 - Tim kiem Sinh vien theo ma Hang");
		printf_s("\n 4 - Liet ke danh sach Sinh Vien dat loai gioi");
		printf_s("\n 5 - Liet ke danh sach Sinh Vien dat loai Kha");
		printf_s("\n 6 - Liet ke danh sach Sinh Vien Phai thi lai");
		printf_s("\n 7 - Tong So Sinh Vien Phai Hoc lai");
		printf_s("\n 8 - Liet ke cac sinh vien sinh vao thang 10:");
		printf_s("\n 9 - Xoa Sinh Vien theo Ma Sinh Vien");
		printf_s("\n 0 - Thoat\n");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
		{
			int n;
			printf_s("\nNhap so luong Sinh vien : ");
			scanf_s("%d", &n);
			for (int i = 1; i <= n; i++)
			{
				printf_s("\nNhap Don vi Sinh vien thu: %d \n", i);
				NhapSV(&x);
			}
			break;

		}
		case 2:
		{
			InDanhSach(x);
			break;
		}
		case 3:
		{
			fflush(stdin);
			printf_s("\nNhap Ma Sinh Vien can tim:");
			scanf_s("%d", &Ma);
			TimKiem(x, Ma);
			break;
		}
		case 4:
		{
			inSVGioi(x);
			break;
		}
		case 5:
		{
			inSVKha(x);
			break;
		}
		case 6:
		{
			inSVThilai(x);
			break;
		}
		case 7:
		{
			SVHocLai(x);
			break;
		}
		case 8:
		{
			inSV10(x);
			break;
		}
		case 9:
		{
			fflush(stdin);
			printf("\nNhap Ma Sinh Vien Xoa:");
			scanf_s("%d", &Ma);
			fflush(stdin);
			XoaSV(&x, Ma);
			break;
		}
		case 0:
		{
			break;
		}
		default: printf_s("\nBan chon sai vui long chon lai!");
		}
	} while (a != 0);
	giaiphong(&x);
	return 1;
}
int main()
{
	//clrscr();
	Menu();
	//clrscr();
	return 0;
}