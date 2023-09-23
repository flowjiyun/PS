#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
  int arr[] = { 2, 2, 4, 5, 3, 1 };
  // int arr[] = { 1, 2, 2, 3, 4, 5 };
  int n = sizeof(arr) / sizeof(arr[0]);

  Print(arr, n);

  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i;
    for (; j > 0; --j) {
      if (key < arr[j - 1]) {
        arr[j] = arr[j - 1];
      } else {
        break;
      }
      cout << "inner";
      Print(arr, n);
    }
    arr[j] = key;
    cout << "outer";
    Print(arr, n);
  }

  Print(arr, n);
  cout << endl;

  return 0;
}