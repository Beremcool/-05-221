#include <cmath>
#include <iomanip>
#include <iostream>
void Solve() {
  int number, left, right, count;
  long double loud, answer;
  std::cin >> number;
  long double* arr = new long double[number];
  for (int i = 0; i < number; i++) {
    std::cin >> loud;
    if (i == 0) {
      arr[i] = log(loud);
    } else {
      arr[i] = log(loud) + arr[i - 1];
    }
  }
  std::cin >> count;
  for (int i = 0; i < count; i++) {
    std::cin >> left >> right;
    if (left == 0) {
      answer = arr[right] / (right - left + 1);
      std::cout << std::setw(11) << std::setprecision(11) << pow(M_E, answer);
    } else {
      answer = (arr[right] - arr[left - 1]) / (right - left + 1);
      std::cout << std::setw(11) << std::setprecision(11) << pow(M_E, answer);
    }
    std::cout << '\n';
  }
  delete[] arr;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  Solve();
  return 0;
}
