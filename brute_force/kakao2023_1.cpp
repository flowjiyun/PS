#include <string>
#include <vector>
#include <iostream>


using namespace std;

// 총 할인율 경우의 수 조합 수 2^14
// 모든 경우의 수 구해서 최적의 값 찾기

int discountRate[4] = {10 , 20, 30, 40};

int rateComb[7] = {0};
vector<vector<int>> gUsers;
vector<int> gEmoticons;
vector<int> gAnswer;

void getSolution(int index) {
    if (index == gEmoticons.size()) {
        int plusUser = 0;
        int emoticonValue = 0;
        for (int i = 0; i < gUsers.size(); ++i) {
			int curEmoticonValue = 0;
            for (int j = 0; j < gEmoticons.size(); ++j) {
                int curDiscountRate = discountRate[rateComb[j]];
				if (gUsers[i][0] <= curDiscountRate) {
					curEmoticonValue += (gEmoticons[j] * (100 - curDiscountRate) / 100);
                }
            }
            if (curEmoticonValue >= gUsers[i][1]) {
				++plusUser;
            } else {
                emoticonValue += curEmoticonValue;
            }
            if (gAnswer.size() == 0) {
				gAnswer.push_back(plusUser);
                gAnswer.push_back(emoticonValue);
            } else if (gAnswer[0] < plusUser || (gAnswer[0] == plusUser && gAnswer[1] < emoticonValue)) {
                gAnswer[0] = plusUser;
                gAnswer[1] = emoticonValue;
            }
        }
        return;
    }
   	for (int i = 0; i < 4; ++i) {
		rateComb[index] = i;
        getSolution(index + 1);
    } 
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    gUsers = users;
    gEmoticons = emoticons;
    getSolution(0);
    return gAnswer;
}

int main() {
    vector<vector<int>> users;
    vector<int> emoticons;
    users.push_back({1, 1});
    emoticons.push_back(1);
    solution(users, emoticons);
    return 0;
}