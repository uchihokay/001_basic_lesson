#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct sinhvien{
	char ten[20];
	char msv[10];
	float dtoan;
};
FILE *f;
const char* filepath = "solieu.c";

void Nhap(int n ){
	sinhvien sv;
	
	f = fopen(filepath,"wb");
	
	for (int i = 0 ; i < n ; i++){
		printf("Ten :");fflush(stdin);
		gets(sv.ten);
		printf("Ma sinh vien :");fflush(stdin);
		gets(sv.msv);
		printf("Diem toan :");
		scanf("%f",&sv.dtoan);
		printf("\n");
		
		fwrite(&sv,sizeof(sinhvien),1,f); 
	}	
	fclose(f); 
}

void In(int n){
	f= fopen(filepath,"rb");
	sinhvien sv;
	
	printf("\n\t\t\t\tBANG SINH VIEN");	
	printf("\n\t|%3s|%20s|%15s|%9s","STT","Ho va Ten","Ma sinh vien","Diem toan");
	printf("\n\t|---|--------------------|---------------|---------|\n");
	
	for(int i = 1 ;i<=n;i++){
		fread(&sv,sizeof(sinhvien),1,f);
		printf("\n\t|%3d|%20s|%15s|%9f",i,sv.ten,sv.msv,sv.dtoan);
	}
	
	fclose(f);
}

int main(){
	int n ,x; 
	sinhvien sv ;
	do{
		 x;
		 printf("\n");
		printf("\n\t\t\t\t |1.Nhap thong tin.   |");
		printf("\n\t\t\t\t |2.In thong tin.     |");
		printf("\n\t\t\t\t |3.Thoat.            |");
		
		printf("\n\t Nhap hanh dong : ");
		scanf("%d",&x);
		if (x==1){
			printf("So luong :");
			scanf("%d",&n);
			Nhap(n);
			printf("\n\tComplete!!!");
		}
		else if ( x==2 ){
			In(n);
			printf("\n\tComplete!!!");
		}	
		else if ( x==3){
			exit(0);
		}
	}while(x<=2);
}
 

