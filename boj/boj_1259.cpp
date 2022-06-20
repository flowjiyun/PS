#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        string val;
        cin >> val;
        int check = 1;
        if (val == "0")
            break;
        for (int i = 0; i < val.size(); i++)
        {
            if (val[i] == val[val.size() - 1 - i])
                continue;
            else
            {
                check = 0;
                break;
            }
        } 
        if (check)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
    return (0);
}