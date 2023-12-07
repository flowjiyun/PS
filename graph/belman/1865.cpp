#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>

using namespace std;


vector<pair<pair<int, int>, int>> graph;
vector<int> dist;


void solve(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            int from = graph[j].first.first;
            int to = graph[j].first.second;
            int cost = graph[j].second;
                if (dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                }
        }
    }
    for (int j = 0; j < graph.size(); ++j) {
        int from = graph[j].first.first;
        int to = graph[j].first.second;
        int cost = graph[j].second;
            if (dist[to] > dist[from] + cost) {
                cout << "YES" << '\n';
                return ;
            }
    }
    cout << "NO" << '\n';
    return;
}

int tc;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        graph.clear();
        dist.clear();
        int a, b, c;
        cin >> a >> b >> c;
        dist = vector(a + 1, 0);
        for (int i = 1; i <= a; ++i) {
            dist[i] = 50000000;
        }
        for (int i = 0; i < b; ++i) {
            int from, to, cost;
            cin >> from >> to >> cost;
            graph.push_back({{from, to}, cost});
            graph.push_back({{to, from}, cost});
        }
        for (int i = 0; i < c; ++i) {
            int from, to, cost;
            cin >> from >> to >> cost;
            graph.push_back({{from, to}, -cost});
        }
        solve(a);
    }

    return 0;
}