#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시작 위치에서 모든 노드를 방문하는 최소 가중치 구하기
// 방문했던 노드 재방문 가능
// 1 -> 2
// 1 -> 3 -> 2
// 가중치는 양수
#define MAXVAL 987654321
int n, startNode;
long long w[11][11];
vector<vector<long long>> memo;

long long tsp(int curNode, int visitedNodes) {
    if (visitedNodes == ((1 << n) - 1)) {
        return 0;
    }

    if (memo[curNode][visitedNodes] != -1) {
        return memo[curNode][visitedNodes];
    }
    memo[curNode][visitedNodes] = MAXVAL;
    for (int nextNode = 0; nextNode < n; ++nextNode) {
        if ((visitedNodes & (1 << nextNode)) == (1 << nextNode)) {
            continue;
        }
        memo[curNode][visitedNodes] = min(memo[curNode][visitedNodes], tsp(nextNode, visitedNodes | (1 << nextNode)) + w[curNode][nextNode]);
    }
    return memo[curNode][visitedNodes];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> startNode;

    memo = vector<vector<long long>>(n, vector<long long>((1 << n) - 1, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    //floyd 
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    cout << tsp(startNode, (1 << startNode));
    return 0;
}