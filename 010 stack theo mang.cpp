#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Max 100
struct stack { 			   	//khai bao stack				
	int top;
	int A[Max];
};

void taostack(stack &s){
	s.top = -1;
}

bool empty(stack &s){
	if (s.top == -1){
		return true;
	}
	else {
		return false ;
	}
}

bool full(stack &s){
	if (s.top  == Max - 1){
		return true ;
	}
	else {
		return false ;
	}
}

void push(stack &s , int x ){
	if (full(s)==false){
		s.top++;
		s.A[s.top] = x;
	}
}

void pop( stack &s) {
	if (empty(s) != true){
		s.top--;
	}
}

void print(stack &s){
	for (int i = s.top ; i> -1;i--){
		printf("%d ",s.A[i]);	
	}
}




int main (){
	stack s;
	taostack(s);
	int n , var ; 
	printf("Nhap n : ");scanf("%d",&n);
	if (n > 0){
		printf("--------------------");
		printf("\n1.Chuyen sang he 2");
		
		
		
		int x ; 
		printf("\n\n\t\tNhap hanh dong :");
		scanf("%d",&x);
		
		if (x == 1){

			while(n != 0 ){
				var = n%2;
				push(s,var);
				n = n / 2;
			}	
			printf("\n\tKet qua : ");
			print(s);		
		}	
	}
}





