#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[100001];
int arr[100001];
bool visited[100001];

void dfs(int start) {
  visited[start]=true;
  for(int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if(!visited[next]) {
      arr[next] = start;
      dfs(next);
    }
  }
}

int main() {
  cin >> n;

  for(int i = 0;i < n; i++) {
      int first, second;
      cin >> first >> second;
      v[first].push_back(second);
      v[second].push_back(first);
  }

  dfs(1);

  for(int i = 2; i <= n; i++) {
    cout << arr[i] << "\n";
  }
}