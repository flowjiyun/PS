//binary search
#include <iostream>
#include <algorithm>

using namespace std;

int input1[100000];
int input2[100000]; 
int n, m;
int binary_search(int val)
{
    int left = 0;
    int right = n - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (input1[mid] == val)
            return 1;
        else if (input1[mid] > val)
        {
            right = mid - 1;
            mid = (left + right) / 2;
            continue;
        }
        else if (input1[mid] < val)
        {
            left = mid + 1;
            mid = (left + right) / 2;
            continue;
        }
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> input1[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> input2[i]; 
    sort(input1, input1 + n);
    for (int i = 0; i < m; i++)
        cout << binary_search(input2[i]) << '\n';
    return (0);
}