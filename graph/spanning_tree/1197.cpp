#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int v, e;
vector<pair<int,pair<int,int>>> vertex;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vertex.push_back({c, {a, b}});
    }
    sort(vertex.begin(), vertex.end());
    graph = vector(v + 1, 0);
    for (int i = 1; i <= v; ++i) {
        graph[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < vertex.size(); ++i) {
        auto curEdge = vertex[i];
        int cost = curEdge.first;
        int from = curEdge.second.first;
        int to = curEdge.second.second;
        if (isInSameSet(from, to)) {
            continue;
        }
        makeUnion(from, to);
        ans += cost;
    }
    cout << ans;
    return 0;
}