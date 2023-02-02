#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> ans;
	vector<int> input;
	input.resize(n + 1);
	ans.resize(n + 1, -100000000);
	for (int i = 1; i <= n; ++i)
	{
		int val;
		cin >> val;
		input[i] = val;
	}
	int sum = 0;
	for (int i = 1; i <= k; ++i)
	{
		sum += input[i];
	}
	ans[1] = sum;
	for (int i = 2; i <= n - (k - 1); ++i)
	{
		ans[i] = ans[i - 1] - input[i - 1] + input[i + (k - 1)];
	}
	cout << *max_element(ans.begin() + 1, ans.begin() + ans.size());
	return (0);
}