#include <iostream>


void swapRef(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void swapPtr(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a = 3;
  int b = 2;

  std::cout << "before swap : " << a << ' ' << b << std::endl;
  swapPtr(&a, &b);
  std::cout << "after swap : " << a << ' ' << b << std::endl;
  return 0;
}