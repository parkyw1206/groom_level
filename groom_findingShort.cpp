#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<vector<bool>> visited;
int N, answer;
bool dfs(int i , int j){
	if(i < 0 || j < 0 || i >= N || j >= N)
		return false;
	else if(v[i][j] != 1)
		return false;
	else if(i == N-1 && j == N-1){
		answer ++;
		v[i][j] = 3;
		return true;
	}
	else{
		answer ++;
		v[i][j] = 3;
		if(dfs(i-1,j)|| dfs(i,j+1) || dfs(i+1,j) || dfs(i,j-1))
			return true;
		answer--;
		v[i][j] = 2;
		return false;
	}
}
int main() {
	int input;	
	cin >> N;
	for(int i = 0 ; i < N; i++){
		v.push_back(vector<int>());
		for(int j = 0 ; j < N ; j++){
			cin >> input;
			v[i].push_back(input);
		}
	}
	answer = 0;
	dfs(0,0);
	
	cout << answer;
	return 0;
}