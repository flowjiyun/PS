#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000000;
vector<vector<int>> combiList;
vector<vector<int>> permuList;
vector<int> curCombi;

void makeCombination(int n, int k, int cnt, int cur) {
    if (cnt == k) {
        combiList.push_back(curCombi);
        return;
    }

    for (int i = cur; i < n; ++i) {
        curCombi.push_back(i);
        makeCombination(n, k, cnt + 1, i + 1);
        curCombi.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
    vector<int> elements = {0, 1, 2};

    cin >> T;

    // 능력 선택 순열 만들기
    do {
        permuList.push_back(elements);
    } while (next_permutation(elements.begin(), elements.end()));

    for (test_case = 1; test_case <= T; ++test_case) {
        vector<int> agentInfo[50];  // 힘, 지능, 민첩, 총합, 능력치 중 최대값
        int n;
        cin >> n;
        for (int agentNum = 0; agentNum < n; ++agentNum) {
            int sum = 0;
            int maxVal = 0;
            for (int i = 0; i < 3; ++i) {
                int val;
                cin >> val;
                sum += val;
                maxVal = max(maxVal, val);
                agentInfo[agentNum].push_back(val);
            }
            agentInfo[agentNum].push_back(sum);
            agentInfo[agentNum].push_back(maxVal);
        }

        // 요원 수가 모자랄 경우 -1
        if (n < 3) {
            cout << "#" << test_case << " " << -1 << '\n';
            continue;
        }

        // 요원 조합 만들기
        makeCombination(n, 3, 0, 0);

        // 각 요원 조합 별 최적의 값 구하기
        int minVal = MAX_VAL;
        for (auto combi : combiList) {
            int remainAgentSum = 0;
            for (int i = 0; i < n; ++i) {
                if (i != combi[0] && i != combi[1] && i != combi[2]) {
                    int curSum = agentInfo[i][3] - agentInfo[i][4];
                    remainAgentSum += curSum;
                }
            }
            for (auto permu : permuList) {
                int curVal = 0;
                for (int index = 0; index < 3; ++index) {
                    int abilSum = agentInfo[combi[index]][3];
                    int pickAbilVal = agentInfo[combi[index]][permu[index]];
                    int remain = abilSum - pickAbilVal;
                    curVal += remain;
                }
                curVal += remainAgentSum;
                minVal = min(minVal, curVal);
            }
        }
        cout << "#" << test_case << " " << minVal << '\n';
        combiList.clear();
        curCombi.clear();
    }

    return 0;
}