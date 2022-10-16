#include <deque>
#include <iostream>
void AddToEnd(std::deque<int>& deka1, std::deque<int>& deka2, int goblin) {
  if (deka1.empty()) {
    deka1.push_front(goblin);
  } else if (deka2.size() == deka1.size()) {
    deka1.push_back(deka2.front());
    deka2.pop_front();
    deka2.push_back(goblin);
  } else {
    deka2.push_back(goblin);
  }
}
void AddToMiddle(std::deque<int>& deka1, std::deque<int>& deka2, int goblin) {
  if (deka2.size() == deka1.size()) {
    deka1.push_back(goblin);
  } else {
    deka2.push_front(goblin);
  }
}
void Vihod(std::deque<int>& deka1, std::deque<int>& deka2) {
  if (deka2.size() == deka1.size()) {
    std::cout << deka1.front() << '\n';
    deka1.pop_front();
    deka1.push_back(deka2.front());
    deka2.pop_front();
  } else {
    std::cout << deka1.front() << '\n';
    deka1.pop_front();
  }
}
int main() {
  std::deque<int> half1, half2;
  char symbol;
  int tests, number;
  std::cin >> tests;
  for (int i = 0; i < tests; i++) {
    std::cin >> symbol;
    if (symbol == '+') {
      std::cin >> number;
      AddToEnd(half1, half2, number);
    } else if (symbol == '*') {
      std::cin >> number;
      AddToMiddle(half1, half2, number);
    } else {
      Vihod(half1, half2);
    }
  }
  return 0;
}
