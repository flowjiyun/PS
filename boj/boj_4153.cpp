#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        vector<int> ans;
        int mx = 0;
        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            int val;
            cin >> val;
            if (mx < val)
            {
                mx = val;
                idx = i;
            }
            ans.push_back(val);
        }
        int isEnd = 1;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != 0)
            {
                isEnd = 0;
                break;
            }
        }
        if (isEnd)
            break;
        if (idx == 2)
        {
            if (ans[0] * ans[0] + ans[1] * ans[1] == ans[2] * ans[2])
                cout << "right" << '\n';
            else
                cout << "wrong" << '\n';
        }
        else if (idx == 1)
        {
            if (ans[0] * ans[0] + ans[2] * ans[2] == ans[1] * ans[1])
                cout << "right" << '\n';
            else
                cout << "wrong" << '\n';
        }
        else
        {
            if (ans[2] * ans[2] + ans[1] * ans[1] == ans[0] * ans[0])
                cout << "right" << '\n';
            else
                cout << "wrong" << '\n';
        } 
    }
    return (0);
}