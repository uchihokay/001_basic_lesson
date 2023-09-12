#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct chuoi {
	int arr1[50];
	int arr2[50];
	int arr3[50];
};
	

void Nhap(int n,int m){
	chuoi x;
	if (m == 1){
		for (int i = 1 ; i <= n ; i++){
			printf("\n%d - ",i);
			scanf("%d",&x.arr1[i]);
		}
	}
	if (m == 2){
		for (int i = 1 ; i <= n ; i++){
			printf("\n%d - ",i);
			scanf("%d",&x.arr2[i]);
		}
	}
		
}
void ghep(int a ,int b ,int c){
	chuoi x;
	for (int i = 1;i <= a ;i++){
		x.arr3[c] = x.arr1[i];
		c++;
	}
	for (int i = 1 ; i <= b; i++){
		x.arr3[c] = x.arr2[i];
		c++;
	}
	
}

void in(int c){
	chuoi x;
	for (int i = 0 ; i<c ; i++){
		printf("%d",x.arr3[i]);
	}
}


int main() {
	int a , b ;
	int c = 0;
	int var;	
	int x = 0;
	
	do{
		printf("\n\n\t\t\t...Menu...");
		printf("\n\t1.Nhap 2 day so");
		printf("\n\t2.Ghep 2 day so");
		printf("\n\t3.In 3 day so");
		printf("\n\t4.Ket thuc");
		
		printf("\nNhap hanh dong : ");
		scanf("%d",&var);
		if (var == 1){
			printf("\n\n\t So luong day 1 :");
			scanf("%d",&a);
			x++;
			Nhap(a,x);
			printf("\n\n\t So luong day 2 :");
			x++;
			scanf("%d",&b);
			Nhap(b,x);
			
			printf("\n\n\t\t\t.....Complete.....");
		}
		
		
		else if (var == 2){
			ghep(a,b,c);
			printf("\n\n\t\t\t.....Complete.....");
			
		}
		
		else if (var == 3){
			in(c);
			printf("\n\n\t\t\t.....Complete.....");
		}
		else if (var == 4){
			exit(0);
		}
		
		
	}while(var>0);
}
