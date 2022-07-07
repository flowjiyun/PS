// 입력 50개로 o(n^2) 풀이로 가능
// 각 데이터를 선형 순회하면서 순위 구하기
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	vector< pair<int, int> > input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> val;
		cin >> val.first >> val.second;
		input.push_back(val);
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if ((input[i].first < input[j].first) && (input[i].second < input[j].second))
				cnt++;
		}
		cout << cnt + 1 << ' ';
	}
	return (0);
}