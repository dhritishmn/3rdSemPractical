#include <iostream>
using namespace std;

int fibonacciIterative(int n) {
  if (n <= 1) {
    return n;
  }

  int fibPrev = 0;
  int fibCurrent = 1;

  for (int i = 2; i <= n; ++i) {
    int temp = fibCurrent;
    fibCurrent = fibPrev + fibCurrent;
    fibPrev = temp;
  }

  return fibCurrent;
}

int main() {
  int n;
  cout << "Enter a positive integer: ";
  cin >> n;

  cout << "Fibonacci (Iterative) of " << n << ": " << fibonacciIterative(n)
       << endl;

  return 0;
}