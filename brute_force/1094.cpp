#include <iostream>
#include <string>


using namespace std;

int target; 
int startLength = 64;
int minLenght, curLength;
int cnt = 0;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> target;
  minLenght = 64;
  curLength = 0;
  if (target == 64) {
    cout << "1";
    return 0;
  }
  while (curLength !=  target) {
    int tmpLength = minLenght / 2;
    if (curLength + tmpLength <= target) {
      curLength += tmpLength;
      cnt++;
    }
    minLenght = tmpLength;
    // cout << "curLength : " << curLength << "cnt : " << cnt << "minLength : " << minLenght << '\n';
  }

  cout << cnt;
  return 0;
}
