#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// 간선 정보 만들기
// 다익스트라 적용 답 구하기
const int MAX_LAST_NODE = 10000;
const int MAX_VAL = 99999;
int s, e;
unordered_map<int, vector<int>> graph;
vector<int> memo;

void makeGraph(int lastNode) {
    int level = 1;
    int levelStartNode = 1;
    while (true) {
        int levelLastNode = levelStartNode + level - 1;
        for (int i = 0; i < level; ++i) {
            int curNode = levelStartNode + i;
            if (curNode > lastNode) {
                break;
            }
            // 동일 레벨에서 우측 노드를 추가 할 수 있으면 추가
            if (curNode + 1 <= levelLastNode && curNode + 1 <= lastNode) {
                int rightNode = curNode + 1;
                graph[curNode].push_back(rightNode);
                graph[rightNode].push_back(curNode);
            }
            // 다음 레벨에 연결되어 있는 노드 추가
            int nextLevelLeftNode = curNode + level;
            int nextLeveRightNode = nextLevelLeftNode + 1;
            if (nextLevelLeftNode <= lastNode) {
                graph[curNode].push_back(nextLevelLeftNode);
                graph[nextLevelLeftNode].push_back(curNode);
            }
            if (nextLeveRightNode <= lastNode) {
                graph[curNode].push_back(nextLeveRightNode);
                graph[nextLeveRightNode].push_back(curNode);
            }
        }
        levelStartNode += level;
        if (levelStartNode > lastNode) {
            break;
        }
        ++level;
    }
}

// 다익스트라로 s노드에서 e노드까지 최단 거리 구하기
int getMinDist() {
    memo = vector<int>(MAX_LAST_NODE + 1, MAX_VAL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, s});
    memo[s] = 0;
    while (!minHeap.empty()) {
        int curDist = minHeap.top().first;
        int curNode = minHeap.top().second;
        minHeap.pop();

        if (curDist > memo[curNode]) {
            continue;
        }

        for (auto nextNode : graph[curNode]) {
            int dist = curDist + 1;
            if (dist < memo[nextNode]) {
                memo[nextNode] = dist;
                minHeap.push({dist, nextNode});
            }
        }
    }
    return memo[e];
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> s >> e;
        makeGraph(max(s, e));
        cout << "#" << test_case << " " << getMinDist() << '\n';
    }
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}