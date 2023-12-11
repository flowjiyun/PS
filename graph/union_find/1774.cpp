#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stdio.h>

using namespace std;

int n,m;
vector<pair<int, int>> nodeInfo;
vector<pair<int, int>> edgeInfo;
vector<pair<double, pair<int, int>>> edgeCandidateInfo;
vector<int> tmp;

vector<int> graph;

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

double getLength(int x1, int y1, int x2, int y2) {
    // int dx = abs(x1 - x2);
    // int dy = abs(y1 - y2);
    // cout << "dx : " << dx << " dy : " << dy << "\n";
    double dx = abs(x1 - x2);
    double dy = abs(y1 - y2);
    return sqrt(dx * dx + dy * dy);
}

void getCombination(int n, int r, int index, int curr) {
   if (index == r)
	{
        int from = tmp[0]; //1
        int to = tmp[1]; //2
        double length = getLength(nodeInfo[from - 1].first, nodeInfo[from - 1].second, nodeInfo[to - 1].first, nodeInfo[to - 1].second);
        edgeCandidateInfo.push_back({length, {from, to}});
		return;
	}
	for (int i = curr; i <= n; ++i)
	{
        tmp.push_back(i);
		getCombination(n, r, index + 1, i + 1);
        tmp.pop_back();
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph = vector(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        graph[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        nodeInfo.push_back({x, y});
    }
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        edgeInfo.push_back({from, to});
    }

    getCombination(n, 2, 0, 1);
    // 후보 간선 오름차순 정렬
    // for (auto val : edgeCandidateInfo) {
    //     cout << val.second.first << ' ' << val.second.second << '\n';
    // }
    sort(edgeCandidateInfo.begin(), edgeCandidateInfo.end());

    //기존 그래프 연결
    for (auto edge : edgeInfo) {
        makeUnion(edge.first, edge.second);
    }

    // mst 만들기
    double ans = 0;
    int cnt = 0;
    for (auto curEdge : edgeCandidateInfo) {
        double cost = curEdge.first;
        int from = curEdge.second.first;
        int to = curEdge.second.second;
        if (isInSameSet(from, to)) {
            continue;
        }
        makeUnion(from, to);
        ans += cost;
        // if (cnt == n - 1) {
        //     break;
        // }
    }
    // cout << fixed << setprecision(2) << ans;
    printf("%.2lf", ans);
    return 0;


}