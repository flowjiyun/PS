#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, j;
	cin >> n >> m;
	int l = 1;
	int r = l + m -1;
	int ret = 0;
	cin >> j;
	while (j--) {
		int pos;
		cin >> pos;
		if (pos > r) {
			int move = pos -r;
			ret += move;
			r = pos;
			l += move;
		}
		else if (pos < l) {
			int move = l - pos;
			ret += move;
			l = pos;
			r -= move;
		}
	}
	cout << ret;
	return (0);
}