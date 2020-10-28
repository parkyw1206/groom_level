#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int endX, endY,l;
queue<pair<int,int>> q;
vector<vector<int>> chess;

bool checkValid(int x, int y){
	if(x < 0 || y<0 || x>= l || y >= l)
		return false;
	else
		return true;
}
int bfs(int startX,int startY){
	int x = startX, y = startY,dist=0;
	bool done= false;
	int temp = 0;
	q.push({x,y});
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		
		if(x==endX && y == endY){
			break;
		}
		q.pop();
		if(checkValid(x+2,y+1) && chess[x+2][y+1] == 0){
			q.push({x+2,y+1});
			chess[x+2][y+1] = chess[x][y]+1;
		}
		if(checkValid(x+2,y-1) && chess[x+2][y-1] == 0){
			q.push({x+2,y-1});
			chess[x+2][y-1] = chess[x][y]+1;
		}
		if(checkValid(x+1,y-2) && chess[x+1][y-2] == 0){
			q.push({x+1,y-2});
			chess[x+1][y-2] = chess[x][y]+1;
		}
		if(checkValid(x+1,y+2) && chess[x+1][y+2] == 0){
			q.push({x+1,y+2});			
			chess[x+1][y+2] = chess[x][y]+1;
		}

		

		if(checkValid(x-2,y-1) && chess[x-2][y-1] == 0){
			q.push({x-2,y-1});
			chess[x-2][y-1] = chess[x][y]+1;
		}
		if(checkValid(x-2,y+1) && chess[x-2][y+1] == 0){
			q.push({x-2,y+1});
			chess[x-2][y+1] = chess[x][y]+1;
		}
		if(checkValid(x-1,y-2) && chess[x-1][y-2] == 0){
			q.push({x-1,y-2});
			chess[x-1][y-2] = chess[x][y]+1;
		}
		if(checkValid(x-1,y+2) && chess[x-1][y+2] == 0){
			q.push({x-1,y+2});
			chess[x-1][y+2] = chess[x][y]+1;			
		}
	
	}
	
	return chess[endX][endY];
}
int main() {
	int startX , startY;
	
	cin >> l ;
	cin >> startX >> startY;
	cin >> endX >> endY;
	
	for(int i = 0 ; i < l ; i ++){
		chess.push_back(vector<int>());
		for(int j = 0 ; j < l ; j++){
			chess[i].push_back(0);
		}
	}
	
	cout << bfs(startX,startY);

	return 0;
}