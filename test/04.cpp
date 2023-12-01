#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

unordered_map<int, int> answerPair;
set<int> roundCards;

int cardLength;
int gCoin;

void makeAnswerPair()
{
    for (int i = 1; i <= cardLength / 2; ++i)
    {
        answerPair[i] = cardLength + 1 - i;
    }
}

vector<pair<int, int>> getNumOfPairInRoundCards()
{
    vector<pair<int, int>> ret;
    for (auto val : roundCards)
    {
        int curAnsPair = answerPair[val];
        if (roundCards.find(curAnsPair) != roundCards.end())
        {
            ret.push_back({val, curAnsPair});
        }
    }
    return ret;
}

int solution(int coin, vector<int> cards)
{
    int roundCnt = 0;
    gCoin = coin;
    cardLength = cards.size();

    makeAnswerPair();

    // init
    for (int i = 0; i < cardLength / 3; ++i)
    {
        roundCards.insert(cards[i]);
    }

    // game start
    while (gCoin > 0 && roundCards.size() > 0)
    {
        vector<pair<int, int>> curPair = getNumOfPairInRoundCards();
        for (auto val : curPair)
        {
            cout << val.first << " " << val.second << endl;
        }
        break;
    }
    return roundCnt;
}