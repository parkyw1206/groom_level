#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n,c, pos = 1,row, col;
	cin >> n;
	vector<pair<int,int>> v;
	int snail[n][2*n];
	
	c = n;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < 2*n ; j++){
			snail[i][j] = 0;
		}
	}
	v.push_back({n,0});
	for(int i = n ; i >= 3 ; i--){
		v.push_back({i,pos});
		if(pos+1 > 3) pos = 0;
		else pos++;
		v.push_back({i,pos});
		if(pos+1 > 3) pos = 0;
		else pos++;
		i--;
	}
	row = 0;
	col = 0;
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v[i].first - 1; j++){
			snail[row][col] = 1;
			if(v[i].second == 0)
				col +=2;
			else if(v[i].second == 1)
				row+=1;
			else if(v[i].second == 2)
				col -= 2;
			else if(v[i].second == 3)
				row-=1;
		}
	}
	snail[row][col] = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < 2*n ; j++){
			if(snail[i][j] == 1)
				cout << "#";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}