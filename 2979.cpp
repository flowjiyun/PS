#include <iostream>

using namespace std;

int t[101];

int	a, b, c;
int s, e;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	for(int i = 0; i < 3; ++i)
	{
		cin >> s >> e;
		for (int j = s; j < e; ++j)
		{
			++t[j];
		}	
	}
	int sum = 0;
	for (int i = 1; i <= 100; ++i)
	{
		if (t[i] == 1)
			sum += a;
		else if (t[i] == 2)
			sum += (b * 2);
		else if (t[i] == 3)
			sum += (c * 3);
	}
	cout << sum;
	return (0);
}