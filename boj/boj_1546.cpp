#include <iostream>

using namespace std;
int arr[1000];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    // 새로운 점수 및 평균
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += static_cast<float>(arr[i]) / max * 100.0;
        
    }
    float ave = static_cast<float>(sum) / n;
    cout << ave;
    return (0);
}