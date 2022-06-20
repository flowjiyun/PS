#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int min  = 1000;
    int arr[4];
    arr[0] = x;
    arr[1] = y;
    arr[2] = w - x;
    arr[3] = h - y;
    for (int i = 0; i < 4; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    cout << min;
    return (0);
}