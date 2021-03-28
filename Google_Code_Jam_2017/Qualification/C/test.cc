#include <iostream>
#include <map>

using namespace std;

bool bigger(int l, int r) {
  return l > r;
}

int main(int argc, char* argv[]) {
  // map<int, int> m([](int l, int r) -> bool { return l > r; });
  map<int, int, bool (*)(int, int)> m(bigger);
  m[1] = 2;
  m[2] = 4;
  m[3] = 6;
  auto fst = *m.begin();
  cout << fst.first << " - " << fst.second << endl;
  cout << min(3, 4) << endl;
  for (const auto kv : m) {
    cout << kv.first << " : " << kv.second << endl;
  }
}
