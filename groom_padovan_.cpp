#include <iostream>
using namespace std;
int main() {
	int input;
	cin >> input;
	input --;
	int nums[50];
	
	nums[0] = 1;
	nums[1] = 1;
	nums[2] = 1;
	for(int i = 3 ; i <= input ; i++){
		nums[i] = nums[i-2] + nums[i-3];
	}
	cout << nums[input];
	return 0;
}