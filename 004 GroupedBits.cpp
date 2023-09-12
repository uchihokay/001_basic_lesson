#include<iostream>
using namespace std;

int main(){
	int n ;
	int a = 0, result = 0;  
	int arr[100];
		
	cin>>n;
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
	
	for (int i = 1 ; i < a ; i++){
		for (int j = i+1;j<a;j++){
			if (arr[j] != arr[i] && arr[i]<arr[j]){
				result += 1;
				break;
			}
			break;
		}
	}
	
	cout<<result;
	return 0;
}
