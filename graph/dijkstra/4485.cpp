#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int intMax = numeric_limits<int>::max();
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, 1, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;

    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<vector<int>> map(n, vector(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int val;
                cin >> val;
                map[i][j] = val;
            }
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({map[0][0], {0, 0}});
        vector<int> memo = vector(n * n + 1, intMax);
        memo[0] = map[0][0];

        while (!minHeap.empty())
        {
            auto curDist = minHeap.top().first;
            auto curPos = minHeap.top().second;
            int curNodeNum = n * curPos.first + curPos.second;
            minHeap.pop();

            if (curDist > memo[curNodeNum])
            {
                continue;
            }
            for (int dir = 0; dir < 4; ++dir)
            {
                int ny = curPos.first + dy[dir];
                int nx = curPos.second + dx[dir];
                // cout << "ny : " << ny << " nx : " << nx << '\n';
                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                {
                    continue;
                }
                int nodeNum = n * ny + nx;
                // cout << "nodeNum : " << nodeNum << '\n';
                int weight = map[ny][nx];
                // cout << "weight : " << weight << '\n';
                int dist = curDist + weight;
                // cout << "dist : " << dist << '\n';

                if (dist < memo[nodeNum])
                {
                    memo[nodeNum] = dist;
                    minHeap.push({dist, {ny, nx}});
                }
            }
        }
        cout << "Problem " << cnt << ": " << memo[n * n - 1] << "\n";
        ++cnt;
    }
    return 0;
}