#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; ++i)
		{
			string a, b;
			cin >> a >> b;
			++m[b];
		}
		long ret = 1;
		for (auto a : m)
			ret *= (a.second + 1);
		cout << ret - 1 << '\n';
	}
	return (0);
}