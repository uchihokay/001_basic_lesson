#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 

struct sinhvien {
	char ten[25];
	char msv[25];
	float dtoan ;
};

struct node {
	sinhvien data;
	node *next;
};
struct list{
	node *phead;
	node *ptail;
};

void CreateList(list &ds){
	ds.phead = NULL;
	ds.ptail = NULL;
}

void InsertEnd(list &ds,node *p){
	if (ds.phead == NULL){
		ds.phead = p ;
		ds.ptail = p;
	}
	else {
		ds.ptail->next = p ;
		ds.ptail = p;
	}
}

void Enter(int n,list &ds){
	sinhvien sv; 
	for (int i = 1 ; i <= n ; i++){
		printf("\n\t\tSinh vien %d \n",i);
		fflush(stdin);
		printf("Ten :"); gets(sv.ten);
		fflush(stdin);
		printf("Ma sinh vien :"); gets(sv.msv);
		printf("Diem toan :"); scanf("%f",&sv.dtoan);
		
		node *p = new node ;
		p->data = sv ;
		p->next = NULL;
		printf("\n");
		InsertEnd(ds,p);
	}
}

void In(list ds){
	node *p = new node ;
	int var = 1 ;		
	if (ds.phead == NULL){
		printf("\n\tChua co thong tin !!!");
	}	
	else {
		printf("\n|%3s|%25s|%15s|%10s","STT","Ho ten ","Ma sinh vien","Diem toan");
		for (p = ds.phead ; p != NULL ; p = p->next){
			printf("\n|%3d|%25s|%15s|%10.2f",var,p->data.ten , p->data.msv , p->data.dtoan);
			var++;
		}
	}
}



int main(){
	int n ; 
	int x;
	list ds;
	CreateList(ds);
	
	do {
		printf("\n\n\n\t\t\tBANG HANH DONG ");
		printf("\n\t\t1.Nhap thong tin .");
		printf("\n\t\t2.In thong tin.");
		
		printf("\nNhap hanh dong : ");scanf("%d",&x);
		if (x == 1){
			printf("So luong sinh vien :");
			scanf("%d",&n);
			Enter(n,ds);
			printf("\n\n\t\t----Complete---- !!!");
		}
		else if (x == 2){
			In(ds);
			printf("\n\n\t\t----Complete---- !!!");
		}
		
		
	}while (x>0);
	
	
	
	
	
	
	
}
