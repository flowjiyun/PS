#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>

using namespace std;

unordered_map<int, vector<int>> outGraph;
unordered_map<int, vector<int>> inGraph;
int visited[1000001];
bool finished[1000001];
int cycleCnt;
int nodeOrder;
int edgeCnt;

int getVertex()
{
    for (auto [key, val] : outGraph)
    {
        if (inGraph.find(key) == inGraph.end())
        {
            return key;
        }
    }
}

void findFeature(int node)
{
    visited[node] = nodeOrder++;

    for (auto nextNode : outGraph[node])
    {
        ++edgeCnt;
        if (visited[nextNode] == -1)
        {
            findFeature(nextNode);
        }
        else if (!finished[nextNode])
        {
            ++cycleCnt;
        }
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer = vector(4, 0);
    for (auto edge : edges)
    {
        int s = edge[0];
        int e = edge[1];
        outGraph[s].push_back(e);
        inGraph[e].push_back(s);
    }
    int vertexNum = getVertex();
    answer[0] = vertexNum;

    vector<int> searchList = outGraph[vertexNum];
    for (auto node : searchList)
    {
        // find visual
        nodeOrder = 0;
        edgeCnt = 0;
        cycleCnt = 0;
        memset(visited, -1, sizeof(visited));
        memset(finished, false, sizeof(finished));
        findFeature(node);
        cout << "node num " << node << " cycleCnt " << cycleCnt << " nodeOrder " << nodeOrder << " edgeCnt " << edgeCnt << endl;
        if (cycleCnt == 1)
        {
            answer[1]++;
        }
        else if (cycleCnt == 0)
        {
            answer[2]++;
        }
        else if (nodeOrder + 1 == edgeCnt)
        {
            answer[3]++;
        }
    }
    return answer;
}