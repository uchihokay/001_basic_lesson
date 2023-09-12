#include<stdio.h>

int main(){
	int a,b;
	int var;
	scanf("%d%d",&a,&b);
	while(b!=0){
		var = a % b ;
		a = b ;
		b = var;
	} 
	printf("%d",a);
}
