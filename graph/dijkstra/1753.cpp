#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <limits>
#include <queue>

using namespace std;

int v, e;
int startNode;
unordered_map<int, vector<pair<int, int>>> adjacentNodes;
vector<int> memo;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    cin >> startNode;

    for (int i = 0; i< e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjacentNodes[u].push_back({v, w});
    }

    memo = vector(v + 1, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, startNode});
    memo[startNode] = 0;

    while (!minHeap.empty())
    {
        int curDist = minHeap.top().first;
        int curNode = minHeap.top().second;
        minHeap.pop();

        if (curDist > memo[curNode])
        {
            continue;
        }

        for (auto edge : adjacentNodes[curNode])
        {
            int neighbor = edge.first;
            int weight = edge.second;
            int dist = curDist + weight;

            if (dist < memo[neighbor])
            {
                memo[neighbor] = dist;
                minHeap.push({dist, neighbor});
            }
        }
    }
    for (int i = 1; i <= v; ++i)
    {
        if (memo[i] == numeric_limits<int>::max())
            cout << "INF\n";
        else
            cout << memo[i] << '\n';
    }

    return 0;
}