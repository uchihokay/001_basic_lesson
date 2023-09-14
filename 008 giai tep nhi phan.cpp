#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

FILE *f;
const char *filepath = "SO_LIEU.c";


struct hanghoa{
	char ten[25];
	int dongia;
	int soluong;
	int thanhtien;
};

void nhap(int n){
	hanghoa x;
	f = fopen(filepath,"wb");
	for (int i = 1 ; i <= n ; i++){
		printf("\nTen hang :");fflush(stdin);
		gets(x.ten);
		printf("\nDon gia :");
		scanf("%d",&x.dongia);
		printf("\nSo luong : ");
		scanf("%d",&x.soluong);
		x.thanhtien = x.dongia * x.soluong;	
		printf("\n");
		
		fwrite(&x,sizeof(hanghoa),1,f);
	}
	fclose(f);
}

void in(int n , int var){
	f = fopen(filepath,"rb");
	hanghoa x;
	
	printf("\n\n%3s %25s %15s %15s %15s","STT","Ten hang","Don gia","So luong","Thanh tien");
	for (int i = 1 ; i <= n + var ; i++){
		fread(&x,sizeof(hanghoa),1,f);
		printf("\n%3d %25s %15d %15d %15d",i ,x.ten , x.dongia , x.soluong , x.thanhtien);
	}
	fclose(f);
}

void bosung( int var){
	f = fopen(filepath,"ab+");
	hanghoa x;
	for (int i = 1 ; i <= var ; i++){
		printf("\nTen hang :");fflush(stdin);
		gets(x.ten);
		printf("\nDon gia :");
		scanf("%d",&x.dongia);
		printf("\nSo luong : ");
		scanf("%d",&x.soluong);
		x.thanhtien = x.dongia * x.soluong;	
		printf("\n");
		
		fwrite(&x,sizeof(hanghoa),1,f);
	}
} 



int main(){
	int n  ; 
	int var = 0;
	int x ;
	do {
		printf("\n\t1.Nhap.");
		printf("\n\t2.Bo sung.");
		printf("\n\t3.Hien thi.");
		printf("\n\t4.Thoat");
		
		printf("\n\t\t\tNhap hanh dong : ");
		scanf("%d",&x);
		if (x == 1){
			printf("\nSo luong hang :");
			scanf("%d",&n);
			nhap(n);
			printf("\n\n\t\tComplete!!!");
		}
		
		else if (x == 2){
			printf("\nSo luong bo sung :");
			scanf("%d",&var);
			bosung(var);
			
		}
		
		
		else if (x == 3){
			if (n>=0){
				in(n,var);
			}
			printf("\n\n\t\tComplete!!!");
		}
		else if (x==4){
			exit(0);
		}
		else if (x>4 && x<0){
			break;
		}
		
		
	}while(x>0);
}



