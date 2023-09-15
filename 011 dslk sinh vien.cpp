#include<stdio.h>            //ham xoa van sai
#include<stdlib.h>
#include<conio.h>

struct sinhvien{
	char ten[25];
	char msv[25];
	int dtoan;
};

struct node {
	sinhvien data;
	node *next;
};

struct list{
	node *phead;
	node *ptail;
};

void taolist(list &ds){
	ds.phead = NULL;
	ds.ptail = NULL;
}

void chencuoi(list &ds,node *p){
	if (ds.phead == NULL){
		ds.phead = p;
		ds.ptail = p;
	}
	else {
		ds.ptail->next = p;
		ds.ptail = p;
	}
}

void nhap(list &ds,int n){	 
	sinhvien x;
	
	for (int i = 0 ; i < n ; i++){
		printf("Ten :");fflush(stdin);
		gets(x.ten);
		printf("Ma sinh vien :");fflush(stdin);
		gets(x.msv);
		printf("Diem toan :");
		scanf("%d",&x.dtoan);
		
		node *p = new node;
		p->data = x;
		p->next = NULL;
		chencuoi(ds,p);
		printf("\n");
	}
}

void in(list ds){
	if (ds.phead == NULL){
		printf("\n\n\tKhong co thong tin!!!");
	}	
	else {
		printf("\n\n %25s %25s %15s ","Ten","Ma sinh vien","Diem toan");
		node *p = new node;
		for (p = ds.phead ; p!= NULL; p = p->next){
			printf("\n %25s %25s %15d",p->data.ten , p->data.msv , p->data.dtoan);
		}
	}	
}

void chen(list &ds){
	sinhvien x;
	int a,k;
	if (ds.phead == NULL){
		printf("Chua co danh sach !!!");
	}
	else{
		printf("Ten :");fflush(stdin);
		gets(x.ten);
		printf("Ma sinh vien :");fflush(stdin);
		gets(x.msv);
		printf("Diem toan :");
		scanf("%d",&x.dtoan);
		node *p = new node;
		p->data = x;
		p->next = NULL;
		
		printf("\n\t1.Chen dau.");
		printf("\n\t2.Chen cuoi.");
		printf("\n\t3.Chen tai vi tri k.");
		
		printf("\nHanh dong : ");
		scanf("%d",&a);
		
		if (a == 1){
			p->next = ds.phead ;
			ds.phead = p;
		}	
		else if (a == 2){
			chencuoi(ds,p);
		}
		
		else if ( a == 3){
			printf("\nVi tri k = ");
			scanf("%d",&k);				
			for (int i = 0 ; i < k-1 ; i++){
				if (k==0){
					p->next = ds.phead ;
					ds.phead = p;
				}
				else {
					node *q = new node;
					q = ds.phead;
					for (int i = 0 ; i<k-1;i++){
						q=q->next;
					}
					p->next = q->next;
					q->next = p;
				}
			}		
		}				
	}
}

void xoa(list &ds){
	int a , k;
	printf("\n\t1.Xoa dau");
	printf("\n\t2.Xoa cuoi");
	printf("\n\t3.Xoa vi tri k");
	printf("\nHanh dong :");
	scanf("%d",&a);
	
	if (a == 1){                    
		node *p = ds.phead;
		ds.phead = ds.phead->next;
		p->next = NULL;
		delete p;
	}
	
	else if (a == 2){
		for (node *p = ds.phead; p!= NULL; p=p->next){
			if (p->next == ds.ptail){
				delete ds.ptail;
				p->next = NULL;
				ds.ptail = p;
			}
		}
	}
	
	else if (a==3){
		printf("\n\tVi tri (k>=1) k = ");
		scanf("%d",&k);
		if (k==1){
			node *p = ds.phead;
			ds.phead = ds.phead->next;
			p->next = NULL;
			delete p;
		}
		else {
			node *m = NULL;
			node *n = ds.phead;
			while(k !=0 ){
				n = n->next;
				m = n;
				k--;
			}
			m->next = n->next;
			delete n;
		}
	}	
}

int main(){
	int n ;
	list ds;
	taolist(ds);	
	int x;
	
	do {
		printf("\n\t\t1.Nhap thong tin .");
		printf("\n\t\t2.In thong tin.");
		printf("\n\t\t3.Chen thong tin.");
		printf("\n\t\t4.Xoa thong tin.");
		printf("\n\t\t5.Sua thong tin");
		printf("\n\t\t6.Ket thuc.");
		
		printf("\nNhap hanh dong :");
		scanf("%d",&x);
		
		if (x == 1){
			printf("\n\tSo luong sinh vien : ");
			scanf("%d",&n);
			nhap(ds,n);
			printf("\n\t\t---Complete---\n");
		}
		
		else if (x == 2){
			in(ds);
			printf("\n\t\t---Complete---\n");
		}
		
		else if (x == 3){
			chen(ds);
			printf("\n\t\t---Complete---\n");
		}
		
		else if (x == 4){
			xoa(ds);
			printf("\n\t\t---Complete---\n");
		}
		
		else if (x == 6){
			printf("\n\t\t---Complete---\n");
			exit(0);
		}
	}while(x>0);
}






