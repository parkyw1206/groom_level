#include <iostream>
#include <algorithm>

using namespace std;
bool isPrime(int num){
	for(int i = 2 ; i < num ; i++){
		if(num % i == 0)
			return false;
	}
	return true;
}
int main() {
	int num;
	bool p;
	cin >> num;
	int arr[num];
	
	for(int i = 0;  i < num; i++){
		arr[i] = i+1;
	}
	do{
		p = true;
		if(isPrime(arr[0] + arr[num-1])){
			for(int j = 0 ; j < num-1 ; j++){
				if(!isPrime(arr[j] + arr[j+1])){
					p = false;
					break;
				}
			}			
		}
		else
			p = false;
		if(p == true){
			for(int j = 0 ; j < num ; j++){
				if(j > 0) cout << " ";
				cout << arr[j];
			}
			cout << endl;
		}
	}while(next_permutation(arr+1,arr+num));
	return 0;
}
