#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> split(string des, string deli)
{
    vector<string> ret;
    string token = "";
    size_t pos = 0;
    while ((pos = des.find(deli)) != string::npos)
    {
        token = des.substr(0, pos);
        ret.push_back(token);
        des.erase(0, pos + deli.length());
    }
    ret.push_back(des);
    return ret;
}

vector<int> changeStringToInt(vector<string> stringDate)
{
    vector<int> ret;
    for (auto val : stringDate)
    {
        ret.push_back(stoi(val));
    }
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    vector<int> todayTransformed;
    unordered_map<string, int> termsMap;
    // today를 int로 변환 추후 계산을 위해서
    todayTransformed = changeStringToInt(split(today, "."));

    // terms parsing
    for (auto val : terms)
    {
        vector<string> tmp;
        tmp = split(val, " ");
        termsMap[tmp[0]] = stoi(tmp[1]);
    }

    // privacies parsing
    int index = 1;
    for (auto val : privacies)
    {
        vector<string> tmp;
        tmp = split(val, " ");
        string curTerm = tmp[1];
        vector<int> curDate = changeStringToInt(split(tmp[0], "."));
        int curMonth = termsMap[curTerm];

        vector<int> calDate(3);

        calDate[0] = curDate[0];

        calDate[1] = curDate[1] + curMonth;

        calDate[2] = curDate[2] - 1;

        if (calDate[1] > 12)
        {
            int year = calDate[1] / 12;
            int month = calDate[1] % 12;
            calDate[0] += year;
            if (month == 0)
            {
                calDate[1] = 12;
                calDate[0]--;
            }
            else
            {
                calDate[1] = month;
            }
        }
        if (calDate[2] == 0)
        {
            calDate[2] = 28;
            calDate[1]--;
            if (calDate[1] == 0)
            {
                calDate[1] = 12;
                calDate[0]--;
            }
        }

        for (int i = 0; i < todayTransformed.size(); ++i)
        {
            if (todayTransformed[i] > calDate[i])
            {
                answer.push_back(index);
                break;
            }
            else if (todayTransformed[i] < calDate[i])
            {
                break;
            }
        }
        ++index;
    }
    return answer;
}