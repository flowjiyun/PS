#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int n, x, y, m;
int ans = 0;
vector<int> v[101];
int visited[101];


void dfs(int start, int end, int num) {
	visited[start] = 1;
	if (start == end) {
		ans = num;
	}
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visited[next]) {
			dfs(next, end, num + 1);
		}
	}
}

int main() {
	cin >> n >> x>> y>> m;


	for (int i = 0; i < m; i++) {
		int first, second;
		cin >> first >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
    	
	dfs(x, y,0);
	if (ans != 0) {
		cout << ans;
	} else {
    cout << "-1";
  }
}