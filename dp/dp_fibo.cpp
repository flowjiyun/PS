#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int fibo(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (memo.find(n) != memo.end()) {
    return memo[n];
  }
  memo[n] = fibo(n - 1) + fibo(n - 2);
  return memo[n];
}

int main() {
  std::cout << fibo(5) << std::endl;
  return 0;
}