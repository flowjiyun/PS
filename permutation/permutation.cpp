#include <iostream>

using namespace std;

bool visted[10];
int ans[10];
int input[10];

int n, r, cnt;

void permute(int n, int r, int pos)
{
	if (pos == r)
	{
		for (int i = 0; i < r; ++i)
			cout << ans[i] << ' ';
		cout << '\n';
		++cnt;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (visted[i]) // 중복  순열 아님
			continue;
		ans[pos] = input[i];
		visted[i] = true;
		permute(n, r, pos + 1);
		visted[i] = false;
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r;
	for (int i = 0; i < n; ++i)
		cin >> input[i];
	permute(n, r, 0);
	cout << cnt << '\n';
	return (0);
}