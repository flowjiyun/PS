#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

int tc;
vector<int> dist;
unordered_map<int, vector<pair<int, int>>> edgeInfo;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--)
    {
        int n, d, c;
        cin >> n >> d >> c;
        edgeInfo.clear();
        for (int i = 0; i < d; ++i)
        {
            int a, b, s;
            cin >> a >> b >> s;
            edgeInfo[b].push_back({a, s});
        }
        dist = vector(n + 1, 987654321);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, c});
        dist[c] = 0;

        while (!minHeap.empty())
        {
            int curTime = minHeap.top().first;
            int curPos = minHeap.top().second;
            minHeap.pop();

            if (curTime > dist[curPos])
            {
                continue;
            }
            for (auto edge : edgeInfo[curPos])
            {
                int nextPos = edge.first;
                int weight = edge.second;
                int time = weight + curTime;

                if (dist[nextPos] > time)
                {
                    dist[nextPos] = time;
                    minHeap.push({time, nextPos});
                }
            }
        }
        int maxTime = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] != 987654321)
            {
                maxTime = max(maxTime, dist[i]);
                cnt++;
            }
        }
        cout << cnt << " " << maxTime << "\n";
    }
    return 0;
}