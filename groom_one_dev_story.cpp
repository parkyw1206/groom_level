#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool checkdouble(int num){
	for(int i = 1 ; i < num ; i++){
		if(i*i == num){
			return true;			
		}
	}
	return false;
}
int main() {
	int num;
	int max=0, eachNum,base = max+1,numT,sum;
	vector<int> arr;
	cin >> num;
	int c = num, index = 0;
	while(c>0){
		eachNum = c % 10;
		arr.push_back(eachNum);
		if(eachNum > max)
			max = eachNum;
		c /= 10;
	}
	base = max+1;
	
	do{
		sum = 0;
		numT = num;
	
		for(int j = arr.size()-1 ; j >= 0 ; j--){
			sum += arr[j]*pow(base,j);
		}
		base++;
	}while(!checkdouble(sum));
	
	cout << base-1;
	return 0;
}