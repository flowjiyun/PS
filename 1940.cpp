// 순서가 상관없는 2개의 순서쌍을 구하는 문제
// 조합문제
#include <iostream>
#include <vector>

using namespace std;

int m, n, ret;
vector<int> dat;

int main(void)
{
	ios::sync_with_stdio(0);
	dat.reserve(15000);

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		dat.push_back(val);
	}

	if (m > 200000)
	{
		cout << "0";
		return (0);
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (dat[i] + dat[j] == m)
					++ret;
			}
		}
		cout << ret;
	}
	return (0);
}