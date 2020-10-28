#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N,dist,dista,distb,distc;
vector<vector<int>> arr;
/*
bool bfs(int x , int y){
	if(x < 0 || y < 0 || x >= N || y >= N)
		return false;
	else if(arr[x][y] != 1)
		return false;
	else if(x == N-1 && y == N-1){
		dist++;
		return true;
	}
	else{
		arr[x][y] = 3;
		dist++;
		if(bfs(x-1,y)  || bfs(x,y+1) || bfs(x+1,y) || bfs(x,y-1))
			return true;
		dist--;
		arr[x][y] = 2;
		return false;
	}
}
*/
bool  checkValid(int x , int y){
	if(x < 0 || y < 0 || x >= N || y >= N)
		return false;
	
	return true;
}
void bfs(int startX , int startY){
	int x = startX , y = startY;
	dista = 0, distb = 0,distc=0;
	
	queue<pair<pair<int,int>,int>> q;
	bool done = false;
	q.push({{x,y},0});
	while(q.size() > 0 && !done){
		x = q.front().first.first;
		y = q.front().first.second;
		distc = q.front().second;
		arr[x][y] = 3;
		
		if(x==N-1 && y == N-1){
			done = true;
			distc++;
			dist = distc;
			break;			
		}

		q.pop();
		
		if(checkValid(x-1,y) && arr[x-1][y] == 1){
			q.push({{x-1,y},distc +1});
		}
		if(checkValid(x,y+1) && arr[x][y+1] == 1){
			q.push({{x,y+1},distc +1});			
		}
		if(checkValid(x,y-1) && arr[x][y-1] == 1){
			q.push({{x,y-1},distc +1});
		}
		if(checkValid(x+1,y) && arr[x+1][y] == 1){
			q.push({{x+1,y},distc +1});			
		}
	}
}
int main() {
	int temp;
	cin >> N;
	
	for(int i = 0 ; i < N; i++){
		arr.push_back(vector<int>());
		for(int j = 0 ; j < N; j++){
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	dist = 0;
	bfs(0,0);
	
	cout << dist << endl;
	return 0;
}
