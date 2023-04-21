#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n = 9;
int k = 7;
int	a[9];

vector<vector<int> > ans;
void comb(int start, int *a, vector<int> b)
{
	if (b.size() == k)
	{
		if (accumulate(b.begin(), b.end(), 0) == 100)
			ans.push_back(b);
		return ;
	}
	for (int i = start + 1; i < n; ++i)
	{
		b.push_back(a[i]);
		comb(i, a, b);
		b.pop_back();
	}
}

int main(void)
{
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	vector<int> b;
	b.reserve(7);
	ans.reserve(100);
	comb(-1, a, b);
	for (auto i : ans[0])
		cout << i << "\n";
	return (0);
}