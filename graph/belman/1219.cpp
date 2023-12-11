#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int n, s, e, m;
vector<pair<pair<int, int>, int>> edge;
int node[51];
long long ans[51];

bool isEndNodeInCycle(int nodeNum, vector<int>& visited) {
    if (visited[nodeNum]) {
        return false;
    }
    if (nodeNum == e) {
        return true;
    } 
    visited[nodeNum] = 1;
    bool ret;
    for (auto info : edge) {
        int from = info.first.first;
        int to = info.first.second;
        if (nodeNum == from) {
           ret |= isEndNodeInCycle(to, visited);
        }
    }
    return ret;
}

void belman() {
    for (int i = 0; i < n - 1; ++i) {
        for (auto info : edge) {
            int from = info.first.first;
            int to = info.first.second;
            int cost = info.second;
            if (ans[from] == LLONG_MIN) {
                continue;
            }
            if (ans[to] < ans[from] - cost + node[to]) {
                ans[to] = ans[from] - cost + node[to];
            }
        }
    }
    bool isPosCycle = false;
    for (auto info : edge) {
        int from = info.first.first;
        int to = info.first.second;
        int cost = info.second;
        if (ans[from] == LLONG_MIN) {
            continue;
        }
        if (ans[to] < ans[from] - cost + node[to]) {
            vector<int> visited = vector(n + 1, 0);
            if (isEndNodeInCycle(from, visited)) {
                isPosCycle = true;
                break;
            }
        }
    }

    if (ans[e] == LLONG_MIN) {
        cout << "gg";
    } else if (isPosCycle) {
        cout << "Gee";
    } else {
        cout << ans[e];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge.push_back({{from, to}, cost});
    }

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        node[i] = val;
    }

    for (int i = 0; i < 51; ++i) {
        ans[i] = LLONG_MIN;
    }
    ans[s] = node[s];

    belman();
    return 0;
}