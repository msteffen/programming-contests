#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> C{1,2,3};
  auto it = C.begin();
  cout << (*it) << endl;
  it--;
  cout << (*it) << endl;
  cout << "it == end? " << (it == C.end());
}
