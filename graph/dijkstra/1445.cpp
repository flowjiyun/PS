#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>


// 1. 간선 가중치는 동일하지만 특정 노드 혹은 노드 주변의 상황에 따라 최소화해야되는 값이 있음
// 2. 우선 순위 (우선 순위 큐를 사용 -> 최소 값이 큐 앞에 저장되고 해당 값을 바라보면서 최적값을 구함)
//      - 쓰레기를 직접 통과하는 경우를 최소로
//      - 주변에 쓰레기가 있는 경우를 최소로
using namespace std;

const int dy[4] = {1,-1,0,0};
const int dx[4] = {0,0,1,-1};

char map[51][51];
int visited[51][51];
int sy, sx, ey, ex;
int ans1 = 0;
int ans2 = 0;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (map[i][j] == 'F') {
				ey = i;
				ex = j;
			}
		}
    }
    // {{쓰레기 직접 통과한 수, 쓰레기 간접 통과한 수}, {y, x}}
	priority_queue<pair<pair<int,int>,pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>> > minHeap;
	minHeap.push({{0,0}, {sy,sx}});
	memset(visited, -1, sizeof(visited));
	visited[sy][sx] = 1;

	while (!minHeap.empty()) {
		int gc = minHeap.top().first.first;
		int gnc = minHeap.top().first.second;
		int y = minHeap.top().second.first;
		int x = minHeap.top().second.second;

		minHeap.pop();

		bool isEnd = false;
		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny == ey && nx == ex) {
				ans1 = gc;
				ans2 = gnc;
				isEnd = true;
				break;
			}

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }

			if (visited[ny][nx] != -1) {
                continue;
            }

			visited[ny][nx] = 1;
			if (map[ny][nx] == 'g') {
				minHeap.push({{gc + 1, gnc}, {ny,nx}});
            } else if (map[ny][nx] == '.') {
				bool isGarbage = false;
				for (int i = 0; i < 4; ++i) {
					if (map[ny + dy[i]][nx + dx[i]] == 'g') {
                        isGarbage = true;
                    } 
				}
				if (isGarbage) {
                    minHeap.push({ {gc,gnc + 1},{ny,nx} });
                } else {
                    minHeap.push({ {gc,gnc},{ny,nx} });
                }
			}
		}
		if (isEnd) {
            break;
        } 
	}
    
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << visited[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }

	cout << ans1 << " " << ans2 << "\n";
	return 0;
}