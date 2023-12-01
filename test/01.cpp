#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<int, int> result;
int map[51][51];

vector<string> split(string toSplit, string delimeter)
{
    vector<string> ret;
    string token = "";
    size_t pos = 0;

    while ((pos = toSplit.find(delimeter)) != string::npos)
    {
        token = toSplit.substr(0, pos);
        ret.push_back(token);
        toSplit.erase(0, pos + delimeter.length());
    }
    ret.push_back(toSplit);
    return (ret);
}

int getRowSum(int index)
{
    int sum = 0;
    for (int i = 0; i < 51; ++i)
    {
        sum += map[index][i];
    }
    return sum;
}

int getColSum(int index)
{
    int sum = 0;
    for (int i = 0; i < 51; ++i)
    {
        sum += map[i][index];
    }
    return sum;
}

int getIndex(vector<string> &friends, string name)
{
    int ret;
    for (int i = 0; i < friends.size(); ++i)
    {
        if (name == friends[i])
        {
            ret = i;
            break;
        }
    }
    return ret;
}
int solution(vector<string> friends, vector<string> gifts)
{
    int answer = 0;
    for (auto gift : gifts)
    {
        vector<string> tmp = split(gift, " ");
        string from = tmp[0];
        string to = tmp[1];
        int fromIndex = getIndex(friends, from);
        int toIndex = getIndex(friends, to);
        map[fromIndex][toIndex]++;
    }

    for (int i = 0; i < friends.size() - 1; ++i)
    {
        for (int j = i + 1; j < friends.size(); ++j)
        {
            string from = friends[i];
            string to = friends[j];

            int fromIndex = getIndex(friends, from);
            int toIndex = getIndex(friends, to);

            if (map[fromIndex][toIndex] != 0 || map[toIndex][fromIndex] != 0)
            {
                if (map[fromIndex][toIndex] > map[toIndex][fromIndex])
                {
                    result[fromIndex]++;
                }
                else if (map[fromIndex][toIndex] < map[toIndex][fromIndex])
                {
                    result[toIndex]++;
                }
                else
                {
                    int fromCost = getRowSum(fromIndex) - getColSum(fromIndex);
                    int toCost = getRowSum(toIndex) - getColSum(toIndex);
                    if (fromCost > toCost)
                    {
                        result[fromIndex]++;
                    }
                    else if (fromCost < toCost)
                    {
                        result[toIndex]++;
                    }
                }
            }
            else
            {
                int fromCost = getRowSum(fromIndex) - getColSum(fromIndex);
                int toCost = getRowSum(toIndex) - getColSum(toIndex);
                if (fromCost > toCost)
                {
                    result[fromIndex]++;
                }
                else if (fromCost < toCost)
                {
                    result[toIndex]++;
                }
            }
        }
    }
    for (auto [key, val] : result)
    {
        answer = max(answer, val);
    }

    return answer;
}

int main(void)
{
    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};
    cout << solution(friends, gifts) << endl;
    return 0;
}