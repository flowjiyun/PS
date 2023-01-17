#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int a[9];
int sum = 0;
vector<int> ans;
pair<int, int> ret;

void solve()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (sum - a[i] - a[j] == 100)
			{
				ret = {i, j};
				return ;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; ++i)
	{
			cin >> a[i];
			sum += a[i];
	}
	solve();
	for (int i = 0; i < 9; ++i)
	{
		if (ret.first == i || ret.second == i)
			continue;
		ans.push_back(a[i]);
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << '\n';
	return (0);
}