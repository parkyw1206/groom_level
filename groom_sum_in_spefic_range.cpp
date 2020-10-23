#include <iostream>
using namespace std;
int main() {
	int n,input,a,b, answer = 0;
	cin >> n;
	int nums[n];
	for(int i = 1 ; i <= n ; i++){
		cin >> input;
		nums[i] = input;
	}
	cin >> a >> b;
	for(int i = a ; i <= b ; i++)
		answer += nums[i];
	cout << answer;
	return 0;
}