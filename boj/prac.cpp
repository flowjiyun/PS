#include <iostream>
#include <vector>

using namespace std;
int coutNum(vector<int> arr, int val)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == val)
            cnt++;
    }
    return cnt;
}
vector<int> solution(vector<int> arr)
{
    vector<int> ans;
    vector<int> wrong;
    wrong.push_back(-1);
    for (int i = 0; i < arr.size(); i++)
    {
        bool isAgain = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isAgain = true;
                break;
            }
        }
        if (!isAgain)
        {
            int result = coutNum(arr, arr[i]);
            if (result > 1)
                ans.push_back(result);
        }
    }
    if (!ans.empty())
        return ans;
    else
        return wrong;
}


int main(void)
{
    vector<int> input = {3, 2, 4, 1};
    vector<int> result = solution(input);
    for (auto c : result)
        cout << c << ' ';
    return (0);
}