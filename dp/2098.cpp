#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 987654321
int n;
int w[17][17];
vector<vector<int>> memo;
int ans;
int startNode;
int tsp(int curNode, int visitedNode) {
    // 모든 노드를 방문 했을 때
    if (visitedNode == (1 << n) - 1) {
        if (w[curNode][startNode] != 0) {
            return w[curNode][startNode];
        } else {
            return MAX;
        }
    }
    // 메모한 값 활용
    if (memo[curNode][visitedNode] != -1) {
        return memo[curNode][visitedNode];
    }
    // 아직 모든 노드를 방문하지 않았을 때 이미 방문하지 않은 노드 방문
    memo[curNode][visitedNode] = MAX;
    for (int nextNode = 0; nextNode < n; ++nextNode) {
        if ((visitedNode & (1 << nextNode)) == (1 << nextNode) || w[curNode][nextNode] == 0) {
            continue;
        }
        memo[curNode][visitedNode] = min(memo[curNode][visitedNode], tsp(nextNode, visitedNode | (1 << nextNode)) + w[curNode][nextNode]);
    }
    return memo[curNode][visitedNode];
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

    memo = vector<vector<int>>(n, vector<int>((1 << n) - 1, -1));
    startNode = 0;
    cout << tsp(0, (1 << 0));
    return 0;
}