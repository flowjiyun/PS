#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <cmath>
#include <algorithm>

// 1. bfs로 섬 판단하면서 섬 정보 기록하기
// 2. 섬 정보를 기반으로 섬끼리 연결하는 조합 구하기
// 3. 조합을 통해 섬간 연결될 수 있는 간선의 가중치구해서 저장하기
// 4. union_find 사용하여 섬 연결하면서 최소 스패닝 트리 찾기

using namespace std;

int n, m;
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};
int map[11][11];
int visited[11][11];
unordered_map<int, vector<pair<int, int>>> islandInfo; // (islandNum, (row, col))
// unordered_map<pair<int, int>, int> pairToNum;
vector<pair<int, pair<int, int>>> edgeInfo; // (cost, (from, to))
vector<int> graph;
queue<pair<int, int>> q;
vector<pair<int, int>> comb;
int islandCnt;
int ans;

int findRoot(int a) {
    if (graph[a] == a) {
        return a;
    }
    graph[a] = findRoot(graph[a]);
    return graph[a];
}

void makeUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) {
        return;
    } else {
        graph[b] = a;
    }
}

bool isInSameSet(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
           cin >> map[i][j];
        }
    }
    islandCnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && map[i][j] == 1) {
                visited[i][j] = 1;
                islandCnt++;
                islandInfo[islandCnt].push_back({i, j});
                q.push({i, j});

                while (!q.empty()) {
                    auto curPos = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int ny = curPos.first + dy[dir];
                        int nx = curPos.second +dx[dir];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                            continue;
                        }
                        if (visited[ny][nx] || map[ny][nx] != 1) {
                            continue;
                        }
                        visited[ny][nx] = 1;
                        q.push({ny, nx});
                        islandInfo[islandCnt].push_back({ny, nx});
                        // pairToNum[{ny, nx}] = islandCnt;
                    }
                }
            }
        }
    }

    for (int i = 1; i < islandCnt; ++i) {
        for (int j = i + 1; j <= islandCnt; ++j) {
            comb.push_back({i, j});
        }
    }

    for (auto val : comb) {
        int from = val.first;
        int to = val.second;
        auto fromPos = islandInfo[from];
        auto toPos = islandInfo[to];
        for (auto fPos : fromPos) {
            int fPosRow = fPos.first;
            int fPosCol = fPos.second;
            for (auto tPos : toPos) {
                int tPosRow = tPos.first;
                int tPosCol = tPos.second;
                bool isIsland = false;
                if (fPosRow - tPosRow == 0) {
                    int dist = abs(fPosCol - tPosCol) - 1;
                    if (dist == 1) {
                        continue;
                    }
                    for (int i = 1; i <= dist; ++i) {
                        if (map[fPosRow][fPosCol + i] == 1) {
                            // if (pairToNum[{fPosRow, fPosCol + i}] == from)
                            isIsland = true;
                            break;
                        }
                    }
                    if (isIsland) {
                        continue;
                    }
                    edgeInfo.push_back({dist, {from, to}});
                } else if (fPosCol - tPosCol == 0) {
                    int dist = abs(fPosRow - tPosRow) - 1;
                    if (dist == 1) {
                        continue;
                    }
                    for (int i = 1; i <= dist; ++i) {
                        if (map[fPosRow + i][fPosCol] == 1) {
                            isIsland = true;
                            break;
                        }
                    }
                    if (isIsland) {
                        continue;
                    }
                    edgeInfo.push_back({dist, {from, to}});
                }
            }
        }
    }

    sort(edgeInfo.begin(), edgeInfo.end());

    graph = vector(islandCnt + 1, 0);
    for (int i = 1; i <= islandCnt; ++i) {
        graph[i] = i;
    }
    int edgeCnt = 0;
    for (auto edge : edgeInfo) {
        int dist = edge.first;
        int from = edge.second.first;
        int to = edge.second.second;

        if (isInSameSet(from, to)) {
            continue;
        }
        makeUnion(from, to);
        ans += dist;
        edgeCnt++;
    }
    // for (auto [key, val] : islandInfo) {
    //     cout << key << '\n';
    //     for (auto v : val) {
    //         cout << v.first << " " << v.second << "\n";
    //     }
    // }
    // for (auto val : comb) {
    //     cout << val.first << " " << val.second << "\n";
    // }
    // for (auto val : edgeInfo) {
    //     cout << val.first << " " << val.second.first << " " << val.second.second << "\n";
    // }
    if (edgeCnt != islandCnt - 1) {
        cout << "-1";
    } else {
        cout << ans;
    }
    return 0;
}