#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>

using namespace std;


unordered_map<int, vector<pair<int, int>>> graph;
vector<int> dist;

int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dist = vector(n + 1, INT_MAX);
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto [key, val] : graph) {
            int from = key;
            for (auto [to, cost] : val) {
                if (dist[from] == INT_MAX) {
                    continue;
                }
                if (dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                }
            }
        }
    }
    for (auto [key, val] : graph) {
        int from = key;
        for (auto [to, cost] : val) {
            if (dist[from] == INT_MAX) {
                continue;
            }
            if (dist[to] > dist[from] + cost) {
                cout << "-1" << '\n';
                return 0;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "-1" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}