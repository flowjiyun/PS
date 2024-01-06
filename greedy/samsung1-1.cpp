#include <math.h>

#include <algorithm>
#include <iostream>

using namespace std;

int s, e;

int getLevel(int num) {
    int level = 1;
    int levelStartNode = 1;
    while (true) {
        int levelLastNode = levelStartNode + level - 1;
        if (num >= levelStartNode && num <= levelLastNode) {
            break;
        }
        levelStartNode += level;
        ++level;
    }
    return level;
}

int getDist() {
    int startNode = min(s, e);
    int endNode = max(s, e);

    if (startNode == endNode) {
        return 0;
    }
    int minNodeLevel = getLevel(startNode);
    int maxNodeLevel = getLevel(endNode);

    int deltaLevel = maxNodeLevel - minNodeLevel;
    int curLevel = minNodeLevel;
    int leftNode = startNode;
    for (int i = 0; i < deltaLevel; ++i) {
        int nextLevel = curLevel + i;
        leftNode += nextLevel;
    }
    int rightNode = leftNode + deltaLevel;
    if (endNode >= leftNode && endNode <= rightNode) {
        return deltaLevel;
    } else if (endNode < leftNode) {
        return deltaLevel + (leftNode - endNode);
    } else {
        return deltaLevel + (endNode - rightNode);
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> s >> e;
        cout << "#" << test_case << " " << getDist() << '\n';
    }
    return 0;
}