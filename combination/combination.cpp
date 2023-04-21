#include <iostream>

using namespace std;

int n, r, cnt;
int input[10];
int ans[10];

void comb(int n, int r, int index, int curr)
{
	if (index == r)
	{
		for (int i = 0; i < r; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		++cnt;
		return;
	}
	for (int i = curr; i < n; ++i)
	{
		ans[index] = input[i];
		comb(n, r, index + 1, i + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	comb(n, r, 0, 0);
	cout << cnt << '\n';
	return (0);
}