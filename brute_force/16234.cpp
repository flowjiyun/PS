#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;


int dy[4]={-1,0,1,0};
int dx[4] ={0,1,0,-1}; 

int visited[51][51];
int space[51][51]; 
int n, l, r, sum, cnt; 

vector<pair<int,int>>v;

void dfs(int y, int x, vector<pair<int,int>> &v){ 
    for(int i=0; i<4; i++){
      int ny = y+dy[i];
      int nx = x+dx[i];
      if(nx<0 || nx>=n || ny<0 || ny>=n || visited[ny][nx]) {
        continue;
      }
      if(abs(space[ny][nx]- space[y][x]) >= l && abs(space[ny][nx] - space[y][x]) <= r){
        visited[ny][nx] = 1;
        v.push_back({ny,nx});
        sum += space[ny][nx];
        dfs(ny,nx,v);
      }
    }
}

int main(){ 
  cin >> n >> l >> r;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> space[i][j];
    }
  }
  while(true){
    bool flag =0;
    //clear visited
    //memset --> good
    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(!visited[i][j]){
          v.clear();
          visited[i][j] = 1;
          v.push_back({i,j});
          sum = space[i][j];
          dfs(i,j,v);
          if(v.size() == 1) continue;  
          for(pair<int,int> b : v){ 
            space[b.first][b.second] = sum / v.size();
            flag = 1;
          }
        } 
      }
    }
    if(!flag) break;  
    cnt++;
  } 
  cout<< cnt << "\n";
  return 0;
}