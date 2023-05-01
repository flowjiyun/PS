#include <iostream>
#include <string>

using namespace std;

string line, ret;
int n;
int map[64][64];

string dfs(int y, int x, int size) {
	if (size == 1)
		return string(1, map[y][x]);
	char temp = map[y][x];
	string ret = "";
	for (int i = y; i < y + size; ++i) {
		for (int j = x; j < x + size; ++j) {
			if (!(temp == map[i][j])) {
				ret += "(";
				ret += dfs(y, x, size / 2);
				ret += dfs(y, x + size / 2, size / 2);
				ret += dfs(y + size / 2, x, size / 2);
				ret += dfs(y + size / 2, x + size / 2, size / 2);
				ret += ")";
				return (ret);
			}
		}
	}
	return (string(1, map[y][x]));
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> line;
		for (int j = 0; j < line.size(); ++j) {
			map[i][j] = line[j];
		}
	}

	ret = dfs(0, 0, n);
	cout << ret;
	return (0);
}