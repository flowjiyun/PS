#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000000;
unordered_map<int, vector<int>> agentInfo;  // 힘, 지능, 민첩, 총합, 능력치 중 최대값
vector<vector<int>> combiList;
vector<vector<int>> permuList;
vector<int> curCombi;
vector<int> pickedCombi;

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
            // cout << "here"
            //      << "\n";
            cout << "#" << test_case << " " << -1 << '\n';
            agentInfo.clear();
            continue;
        }

        // 요원 조합 만들기
        makeCombination(n, 3, 0, 0);

        // 각 요원 조합 별 최적의 값 구하기
        int minVal = MAX_VAL;
        for (auto combi : combiList) {
            int remainAgentSum = 0;
            for (const auto [key, val] : agentInfo) {
                if (key != combi[0] && key != combi[1] && key != combi[2]) {
                    int curSum = val[3] - val[4];
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
                // if (minVal >= curVal) {
                //     minVal = curVal;
                //     pickedCombi = combi;
                // }
                minVal = min(minVal, curVal);
            }
        }
        // cout << "pickedCombi : " << pickedCombi[0] << " " << pickedCombi[1] << " " << pickedCombi[2] << '\n';
        // int remainAgentSum = 0;
        // for (const auto [key, val] : agentInfo) {
        //     if (key != pickedCombi[0] && key != pickedCombi[1] && key != pickedCombi[2]) {
        //         int curSum = val[3] - val[4];
        //         remainAgentSum += curSum;
        //     }
        // }
        // cout << "minVal : "
        //      << minVal << "\n";
        // cout << "remainAgentSum : "
        //      << remainAgentSum << "\n";
        // int result = minVal + remainAgentSum;
        // cout << "#" << test_case << " " << result << '\n';
        cout << "#" << test_case << " " << minVal << '\n';
        agentInfo.clear();
        combiList.clear();
        curCombi.clear();
        pickedCombi.clear();
    }

    return 0;
}