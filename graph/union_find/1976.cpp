#include <iostream>
#include <vector>

using namespace std;

int n, m;

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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    graph = vector(n + 1, 0);
    for (int i = 0; i < graph.size(); ++i) {
    graph[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            if (val == 1) {
                makeUnion(i + 1, j + 1);
            }
        }
    }
    int root;
    for (int i = 0; i < m; ++i) {
        int node;
        cin >> node;
        if (i == 0) {
            root = findRoot(node);
        } else {
            if (root != findRoot(node)) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}