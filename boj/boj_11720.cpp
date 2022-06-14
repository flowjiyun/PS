#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string val;
    int result = 0;
    cin >> val;
    for (int i = 0; i < n; i++)
    {
        result += val[i] - '0';
    }
    cout << result;

    return (0);
}