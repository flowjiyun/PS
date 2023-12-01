#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int getSumOfDice(const vector<int> &curDice)
{
    int sum = 0;
    for (auto val : curDice)
    {
        sum += val;
    }
    return sum;
}

int getVariance(const vector<int> &curDice)
{
}

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    int index = 1;
    for (const auto &curDice : dice)
    {
        int sum = getSumOfDice(curDice);
        cout << index << " : " << sum << endl;
        cout << "average " << sum / 6.0 << endl;
        index++;
    }
    return answer;
}