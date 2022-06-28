//팩토리얼 구현
// 입력값 10이하
#include <iostream>

using namespace std;
int Factorial(int val)
{
    if (val == 0)
        return 1;
    return (val * Factorial(val - 1));
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int result = Factorial(n) / (Factorial(k) * Factorial(n - k));
    cout << result;
    return (0);
}