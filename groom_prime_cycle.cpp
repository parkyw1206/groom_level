#include <iostream>
#include <algorithm>

using namespace std;
bool isprime(int num){
	if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11
			|| num == 13 || num == 17 || num == 19 || num == 23 
			|| num == 29)
		return true;
	else
		return false;
}
int main() {
	int input;
	cin >> input;
	bool notP;
	int arr[input+1];
	int sum = 0;
	for(int i = 1; i <= input ; i++){
		arr[i] = i;
	}
	do{
		int left = 1,right = 2;
		notP = false;
		sum = arr[left]+ arr[right];
		while(left <= input){
			if(!isprime(sum)){
				notP = true;
				break;
			}
			else{
				sum -= arr[left];
				left++;
				if(left == input)
					right = 1;
				else
					right++;
				sum += arr[right];
			}
		}
		if(notP == false){
			for(int j = 1 ; j <= input; j++){
				cout << arr[j];
				if(j == input)
					cout << endl;
				else
					cout << " ";
			}
		}
	}while(next_permutation(arr+2,arr+input+1));
	return 0;
}

#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello World";

    return 0;
}
