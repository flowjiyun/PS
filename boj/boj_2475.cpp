// 2475 검증수
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 5;
    int sum = 0;
    while (n--)
    {  
        int val;
        cin >> val;
        sum += val * val;        
    }
    cout << sum % 10;
    return (0);
}