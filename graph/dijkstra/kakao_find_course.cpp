#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

unordered_map<int, vector<pair<int, int>>> graph;
vector<int> intensity;
const int maxVal = numeric_limits<int>::max();
bool isSummit[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> answer;
    // make graph
    for (auto path : paths)
    {
        int s = path[0];
        int e = path[1];
        int w = path[2];
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }

    // check summit
    for (auto summit : summits)
    {
        isSummit[summit] = true;
    }

    intensity = vector(n + 1, maxVal);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    // init start point
    for (auto gate : gates)
    {
        intensity[gate] = 0;
        minHeap.push({intensity[gate], gate});
    }
    // dijkstra
    while (!minHeap.empty())
    {
        int curIntensity = minHeap.top().first;
        int curNode = minHeap.top().second;
        minHeap.pop();

        if (intensity[curNode] != curIntensity)
        {
            continue;
        }
        for (auto nextNodeInfo : graph[curNode])
        {
            int nextNode = nextNodeInfo.first;
            int nextNodeWeight = nextNodeInfo.second;
            if (intensity[nextNode] > max(intensity[curNode], nextNodeWeight))
            {
                intensity[nextNode] = max(intensity[curNode], nextNodeWeight);
                if (!isSummit[nextNode])
                {
                    minHeap.push({intensity[nextNode], nextNode});
                }
            }
        }
    }
    int ansSummit = summits[0];
    for (auto summit : summits)
    {
        if (intensity[summit] < intensity[ansSummit])
        {
            ansSummit = summit;
        }
        else if (intensity[summit] == intensity[ansSummit] && summit < ansSummit)
        {
            ansSummit = summit;
        }
    }
    answer.push_back(ansSummit);
    answer.push_back(intensity[ansSummit]);
    return answer;
}