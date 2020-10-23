#include <iostream>
using namespace std;
int main() {
	int N, temp;
	cin >> N;
	
	int arr[N];
	for(int i = 0; i < N ; i++){
		cin >> temp;
		arr[i] = temp;
	}
	
	int left = 0;
	int right = 0;
	int max = 1;
	int maxIndex = 0;
	int sumIndex = 0;
	while(right < N){	
		if(arr[right] <= arr[right+1]){
			sumIndex++;
			right++;

		}
		else {
			sumIndex++;
			if(max < sumIndex)
				max = sumIndex;
			sumIndex=0;
			right++;
			left = right;
		}
		//cout <<"From " << left << " to " << right << "-->" << sumIndex << endl;

		if(max < sumIndex)
			max = sumIndex;
	}
	cout << max << endl;
	return 0;
}