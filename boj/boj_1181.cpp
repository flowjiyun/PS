#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string arr[20000];
bool cmp(const string& a, const string& b)
{
    if (a.length() > b.length())
        return false;
    else if (a.length() < b.length())
        return true;
    else
        return a < b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];     
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        cout << arr[i] << '\n';
    }
    return (0);
}