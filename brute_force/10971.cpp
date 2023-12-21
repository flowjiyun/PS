#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n;
int w[11][11];
int ans;
int visitedNode;
int startNode;
void tsp(int curNode, int visitedNode, int curWeight) {
    visitedNode |= (1 << curNode);
    // 모든 노드를 방문 했을 때
    if (visitedNode == (1 << n) - 1) {
        if (w[curNode][startNode] != 0) {
            curWeight += w[curNode][startNode];
            ans = min(ans, curWeight);
        } else {
            ans = min(ans, INT_MAX);
        }
        return;
    }
    // 아직 모든 노드를 방문하지 않았을 때 이미 방문하지 않은 노드 방문
    for (int nextNode = 0; nextNode < n; ++nextNode) {
        if (visitedNode & (1 << nextNode) || w[curNode][nextNode] == 0) {
            continue;
        }
        curWeight += w[curNode][nextNode];
        // visitedNode |= (1 << nextNode);
        tsp(nextNode, visitedNode, curWeight);
        curWeight -= w[curNode][nextNode];
        // visitedNode &= ~(1 << nextNode);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }

    ans = INT_MAX;
    startNode = 0;
    tsp(0, 0, 0);
    cout << ans;
    return 0;
}