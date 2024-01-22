#include <iostream>

int gcdRecursive(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcdRecursive(b, a % b);
  }
}

int main() {
  int num1, num2;
  std::cout << "Enter two positive integers: ";
  std::cin >> num1 >> num2;

  int result = gcdRecursive(num1, num2);

  std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result
            << std::endl;

  return 0;
}