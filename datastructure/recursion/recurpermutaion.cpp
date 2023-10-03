#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

void RecurPermutations(char* arr, int left, int right)
{
	// arr[left], ..., arr[right]

	if (left == right)
	{
		for (int i = 0; i <= right; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		// 힌트
		// - for, swap(), 재귀호출
		// - 같은 변수끼리도 swap() 가능
		// - right는 고정

		// TODO:
    for (int i = left; i <= right; ++i) {
      swap(arr[left], arr[i]);
      RecurPermutations(arr, left + 1, right);
      swap(arr[left], arr[i]);
    }
	}
}

int main()
{
	// Permutations
	char arr[] = "abcd";

	RecurPermutations(arr, 0, 0);
	cout << endl;

	RecurPermutations(arr, 0, 1);
	cout << endl;

	RecurPermutations(arr, 0, 2);
	cout << endl;

	// RecurPermutations(arr, 0, 3);
	// cout << endl;

	return 0;
}