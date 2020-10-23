#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N,temp,maxNum = 0;
	cin >> N;
	vector<vector<int>> v, arr;
	
	for(int i = 0 ; i < N ; i++){
		v.push_back(vector<int>());
		arr.push_back(vector<int>());
		for(int j = 0 ; j <= i ; j++){
			cin >> temp;
			v[i].push_back(temp);
			arr[i].push_back(0);
		}
	}
	
	arr[0][0] = v[0][0];
	
	for(int i = 1 ; i < N ; i++){
		for(int j = 0 ; j < v[i].size(); j++){
			if(j > 0 && j < arr[i].size() -1 )
				arr[i][j] = v[i][j] + max(arr[i-1][j-1] , arr[i-1][j]);
			else if(j == arr[i].size()-1)
				arr[i][j] = v[i][j] + arr[i-1][j-1];
			else if(j == 0)
				arr[i][j] = v[i][j] + arr[i-1][j];
			
			if(maxNum < arr[i][j])
				maxNum = arr[i][j];
		}
	}	
	cout << maxNum ;
	return 0;
}