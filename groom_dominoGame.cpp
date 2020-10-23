#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int a,b,c,x,y,start,answer = 0, tempNum = 0;
	bool drop[a];
	vector<int> startVec;
	map<int,int> m;
	
	cin >> a>> b>> c;
	for(int i = 0 ; i <= a ; i++){
		drop[i] = false;
	}
	for(int i = 0 ; i < b ; i++){
		cin >> x >> y;
		m[x] = y;
	}
	for(int i = 0 ; i< c ; i++){
		cin >> start;
		startVec.push_back(start);
	}
	sort(startVec.begin(), startVec.end());
	while(startVec.size() > 0){
		tempNum = startVec[0];
		
		while(m[tempNum] > 0){
			m[tempNum] = 0;
			drop[tempNum] = true;
			tempNum++;
		}
		drop[tempNum] = true;
		startVec.erase(startVec.begin());
	}
	for(int i = 1 ; i <= a ; i++){
		if(drop[i] == true){
			answer ++;			
		}
	}
	cout<< answer << endl;
	return 0;
}