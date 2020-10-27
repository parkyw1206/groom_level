#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N,K,remainPpl,point = 0;
	cin >> N >> K;
	vector<int> arr;
	
	for(int i = 0 ; i < N ; i++){
		arr.push_back(i+1);
	}
	
	K--;
	remainPpl = N;
	
	while(remainPpl > 2){
		arr.erase(arr.begin()+point);
		point += K; 
		remainPpl--;
		if(point >= remainPpl){
			point %= remainPpl;
		}
	}
	
	for(int i = 0 ; i < 2 ; i++){
		cout << arr[i];
		if(i == 0) cout << " ";
	}
	
	return 0;
	
}