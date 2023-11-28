#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;


vector<vector<string>> gRelation;
int rowSize, colSize;

bool isMinimal(vector<int>& curRet, int curComb) {
    for(int i = 0; i < curRet.size(); i++) {
        // 중복 되는 열이 모두 포함되면 최소성 만족 안됨
        if ((curRet[i] & curComb) == curRet[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    rowSize = relation.size();
    colSize = relation[0].size();
    vector<int> ret;
    // 비트마스킹으로 모든 조합 탐색
    for (int i = 1; i < (1 << colSize); ++i) {
        set<string> combs;
        // 모든 행의 값을 체크
        for (int j = 0; j < rowSize; ++j) {
            string comb = "";
            for (int k = 0; k < colSize; ++k) {
                // 선택한 열이 조합에 포함되는 열이면 문자에 추가
                if (i & (1 << k)) {
                    comb += relation[j][k];
                }
            }
            combs.insert(comb);
        }
        if (combs.size() == rowSize && isMinimal(ret, i))
        {
            ret.push_back(i);
        }
    }
    answer = ret.size();
    return answer;
}