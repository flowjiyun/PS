#include <iostream>

using namespace std;

int n, r, cnt;
int input[10];
int ans[10];

void comb(int n, int r, int index, int curr)
{
	cout << "curr : " << curr << '\n';
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
		//후위 연산으로 인해 현재 위치(curr)에 있는 수를 한번 더 뽑을 수 있게 짐
		// 중복 조합 가능해짐
		comb(n, r, index + 1, curr++);
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