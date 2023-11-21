#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
using namespace std;

int targetAlp;
int targetCop;
int startAlp;
int startCop;

const int MAXVAL = numeric_limits<int>::max();
vector<vector<int>> memo;
vector<vector<int>> gProblems;

int dp(int curAlp, int curCop)
{
    if (curAlp >= targetAlp && curCop >= targetCop)
    {
        return 0;
    }
    curAlp = min(curAlp, targetAlp);
    curCop = min(curCop, targetCop);
    if (memo[curAlp][curCop] != 0)
    {
        return memo[curAlp][curCop];
    }
    memo[curAlp][curCop] = MAXVAL;
    memo[curAlp][curCop] = min(memo[curAlp][curCop], dp(curAlp + 1, curCop) + 1);
    memo[curAlp][curCop] = min(memo[curAlp][curCop], dp(curAlp, curCop + 1) + 1);
    for (auto problem : gProblems)
    {
        int alpReq = problem[0];
        int copReq = problem[1];
        int alpRwd = problem[2];
        int copRwd = problem[3];
        int cost = problem[5];
        if (curAlp >= alpReq && curCop >= copReq)
        {
            memo[curAlp][curCop] = min(memo[curAlp][curCop], dp(curAlp + alpRwd, curCop + copRwd) + cost);
        }
    }
    return memo[curAlp][curCop];
}
int solution(int alp, int cop, vector<vector<int>> problems)
{
    int answer = 0;
    gProblems = problems;
    for (auto problem : problems)
    {
        targetAlp = max(targetAlp, problem[0]);
        targetCop = max(targetCop, problem[1]);
    }
    memo = vector(targetAlp + 1, vector(targetCop + 1, 0));
    answer = dp(alp, cop);
    return answer;
}