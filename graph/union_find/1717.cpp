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

    cin >> n >> m;
    int command, a, b;
    graph = vector(n + 1, 0);
    // rootCheck = vector(n + 1, -1);
    // ranks = vector(n + 1, 0);
    for (int i = 0; i < graph.size(); ++i) {
        graph[i] = i;
    }
    while (m--) {
        cin >> command >> a >> b;
        if (command == 0) {
            makeUnion(a, b);
        } else if (command == 1) {
            if (isInSameSet(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}