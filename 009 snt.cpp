#include<stdio.h>
#include<conio.h>


bool snt(int n ){
	int var = 0 ;
	for (int i = 1 ; i <= n ; i++){
		if (n%i==0){
			var++;
		}
	}
	if (var == 2){
		return true ;
	}
	else {
		return false;
	}
}


int main(){
	int arr0[50];    				    // chuoi nhap
	int arr1[50];    					//so nguyen to
	int arr2[50];    					// so thuong
	int n ; 
	
	printf("Nhap n (n >=5 ) :");scanf("%d",&n);
	if (n<5){
		printf("n >= 5");
	}
	else {
		for (int i = 0 ; i < n ; i++){
			scanf("%d",&arr0[i]);
		}
	}
	
	for (int i = 0 ; i < n ; i++){          //sap xep chuoi
		for (int j = i+1 ; j<n ; j++){
			if (arr0[i]>arr0[j]){
				int bien ; 
				bien = arr0[i];
				arr0[i] = arr0[j];
				arr0[j] = bien ;
			}
		}
	}
	
	int a = 0 ;
	int b = 0 ; 
	int c = 0 ;        //kiem tra so 1 
	
	for (int i = 0 ; i < n ; i++){
		if (arr0[i] == 1){
			c++;
			break;
		}
	}
	
	
	for (int i = 0 ; i < n ; i++){
		if (snt(arr0[i]) == true ){
			arr1[a] = arr0[i];
			a++;
		}
		else if  (snt(arr0[i]) == false && arr0[i] != 1){
			arr2[b] = arr0[i];
			b++;
		}
	}
	
	
	for (int i = 0 ; i < a ; i++){
		printf("%d ",arr1[i]);
	}
	for (int i= 0 ; i < b ; i++){
		printf("%d ",arr2[i]);
	}
	if (c==1){
		printf("1");
	}
	
	
	
}
