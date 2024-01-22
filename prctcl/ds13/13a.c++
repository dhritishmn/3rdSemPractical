#include <iostream>

int gcdIterative(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int num1, num2;
  std::cout << "Enter two positive integers: ";
  std::cin >> num1 >> num2;

  int result = gcdIterative(num1, num2);

  std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result
            << std::endl;

  return 0;
}