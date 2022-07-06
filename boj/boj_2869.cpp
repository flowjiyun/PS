//입력이 10억 이상이라 시간 초과 유의 해야 할 문제
// 수학식으로 특정 값에 대한 점화식을 만들어야 함
// 목표 높이 - 낮에 올라갈 수 있는 높이 까지만 올라가게 되면 무조건 다음날 도달 할 수 있음
// 위의 아이디어를 가지고 구현
#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, v;
	cin >> a >> b >> v;
	int day = (v - a) / (a - b);
	if (a >= v)
		cout << '1';
	else if ((v - a) % (a - b))
		cout << day + 2;
	else
		cout << day + 1;
	return (0);
}