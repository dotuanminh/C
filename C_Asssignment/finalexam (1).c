#include<stdio.h>
#include<string.h>

typedef struct thongtin{
	char *name[30];
	char *mssv[12];
	char *que[30];
	float GPA;
}sinhvien;
int tongsv;

void nhap(){
	int i;
	sinhvien sv[tongsv];
	printf("Nhap so luong sinh vien:\n");
	scanf("%d",&tongsv);
	fflush(stdin);
	while(tongsv<0){
		printf("So sinh vien khong dung. Nhap lai:\n");
		scanf("%d",&tongsv);
		fflush(stdin);
	}
		
	for(i=0;i<tongsv;i++){
		printf("Sinh vien thu %d\n",i+1);
		printf("Nhap ten sinh vien %d:\n",i+1);
		fflush(stdin);
		gets(sv[i].name);
		printf("Nhap ma so sinh vien %d:\n",i+1);
		fflush(stdin);
		gets(sv[i].mssv);
		printf("Nhap que quan sinh vien %d:\n",i+1);
		fflush(stdin);
		gets(sv[i].que);
		printf("Nhap GPA sinh vien %d:\n",i+1);
		fflush(stdin);
		scanf("%f",&sv[i].GPA);
		fflush(stdin);
		while(sv[i].GPA<0||sv[i].GPA>4){
			printf("Nhap lai GPA sinh vien\n");
			scanf("%f",&sv[i].GPA);
		}
	}
}

void in(){
	int i,tongGPA=0;
	sinhvien sv[tongsv];
		printf("%-5s%-30s%-12s%-30s%s\n","STT","Ten","MSSV","QueQuan","GPA");
		for(i=0;i<tongsv;i++){
		printf("%-5d%-35s%-12s%-30s%.2f\n",i+1,sv[i].name,sv[i].mssv,sv[i].que,sv[i].GPA);
		tongGPA=tongGPA+sv[i].GPA;
		}
	printf("Diem GPA trung binh cua sinh vien la: %f ",tongGPA/tongsv);
	printf("\n");
int main(){
}

	int choice;
	sinhvien sv[tongsv];
	for(;;){
		int i;
		printf("1 Nhap thong tin sinh vien\n");
		printf("2 In thong tin sinh vien\n");
		printf("3 Tim theo ma so sinh vien\n");
		printf("4 Tim theo GPA va que quan sinh vien\n");
		printf("5 Sap xep\n");
		printf("6 Thoat\n");
		printf("Chon 1 chuc nang: \n");
		scanf("%d",&choice);
		while(choice<1||choice>6){
		printf("Khong ton tai. Nhap lai:\n");
		scanf("%d",&choice);
		}
	switch(choice){
		case 1:
			nhap();
			break;
		case 2:
			nhap();
			in();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}	
}
	return 0;
}
