#include <iostream>
struct Node {
  int value;
  Node* next;
  Node* previous;
  Node(int val) : value(val), next(NULL), previous(NULL) {}
};
struct Queue {
  Node *first, *last;
  int count;
  Queue() : first(NULL), last(NULL) { count = 0; };
  bool Empty() { return count == 0; };
  void PushCout(int iq) {
    Push(iq);
    std::cout << "ok" << '\n';
  }
  void Push(int iq) {
    Node* newnumber = new Node(iq);
    if (Empty()) {
      delete first;
      first = newnumber;
      delete last;
      last = newnumber;
      count = count + 1;
    } else {
      newnumber->previous = last;
      last->next = newnumber;
      last = newnumber;
      count = count + 1;
    }
  }
  void Pop() {
    if (!Empty()) {
      Node* help;
      help = first->next;
      delete first;
      if (count == 1) {
        last = NULL;
      }
      first = help;
      count = count - 1;
    }
  }
  void PopEnd() {
    if (count > 1) {
      Node* help;
      help = last->previous;
      delete last;
      last = help;
      count = count - 1;
    } else if (count == 1) {
      delete first;
      first = NULL;
      last = NULL;
      count = count - 1;
    }
  }
  void PopCout() {
    if (Empty()) {
      std::cout << "error" << '\n';
    } else {
      std::cout << FrontNumber() << '\n';
      Pop();
    }
  }
  void Front() {
    if (Empty()) {
      std::cout << "error" << '\n';
    } else {
      std::cout << first->value << '\n';
    }
  }
  int FrontNumber() {
    if (Empty()) {
      return 0;
    }
    return first->value;
  }
  int LastNumber() {
    if (Empty()) {
      return 0;
    }
    if (count == 1) {
      return first->value;
    }
    return last->value;
  }
  void Size() { std::cout << count << '\n'; };
  void Clear() {
    while (first != NULL) {
      Pop();
    }
  }
  void ClearOk() {
    Clear();
    std::cout << "ok" << '\n';
  }
};
void Mini(Queue& dataofmins) { dataofmins.Front(); }
void PushMini(Queue& dataofmins, int number) {
  while (dataofmins.LastNumber() > number) {
    dataofmins.PopEnd();
  }
  dataofmins.Push(number);
}
void PopMini(Queue& ocered, Queue& dataofmins) {
  if (ocered.FrontNumber() == dataofmins.FrontNumber()) {
    dataofmins.Pop();
  }
}
void Solve() {
  int n, m;
  std::cin >> m;
  Queue shlyapa, minimumy;
  std::string comand;
  for (int i = 0; i < m; i++) {
    std::cin >> comand;
    if (comand == "enqueue") {
      std::cin >> n;
      shlyapa.PushCout(n);
      PushMini(minimumy, n);
    } else if (comand == "dequeue") {
      PopMini(shlyapa, minimumy);
      shlyapa.PopCout();
    } else if (comand == "front") {
      shlyapa.Front();
    } else if (comand == "size") {
      shlyapa.Size();
    } else if (comand == "clear") {
      shlyapa.ClearOk();
      minimumy.Clear();
    } else {
      Mini(minimumy);
    }
  }
  shlyapa.Clear();
  minimumy.Clear();
}
int main() {
  Solve();
  return 0;
}
