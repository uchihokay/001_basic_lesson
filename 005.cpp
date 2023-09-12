#include<iostream>
using namespace std;
int countBitsPrime(int L, int R)
{
	int a = 0;
	
	
	for (int n = L ; n >=L && n << R ; n++){
		int a = 0, result = 0;  
		int arr[100];
		int var = 0 ;	

		while(n!=0){
			if (n % 2==0 ){
				arr[a] = 0;
				a++;
			}
			else{
				arr[a] = 1;
				a++;
			}
			n = n / 2;
		}
	
		if (arr[0] == 1){
			result ++;
		}

		for (int i = 0 ; i < a ; i++){
			for (int j = i+1;j<a;j++){
				if (arr[j] != arr[i] && arr[i]<arr[j]){
					result += 1;
					break;
				}
				break;
			}
		}
		for (int i = 2 ; i < result ; i++){
			if (result % i ==0){
				var ++;
			}
		}
		
		if (var == 0){
			a++;
		}	 
	}
	
	cout<<a;
}




int main(){
	int l,r;
	cin>>l>>r;
	countBitsPrime(l,r);
}
