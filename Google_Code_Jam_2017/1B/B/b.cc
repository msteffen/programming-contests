#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

ostream& operator<<(ostream &os, const vector<char>& v) {
  for(char c : v) {
    os << c;
  }
  return os;
}

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    map<char, int> ct;
    int N;
    cin >> N >> ct['R'] >> ct['O'] >> ct['Y'] >> ct['G'] >> ct['B'] >> ct['V'];
    vector<char> stall;
    stall.reserve(N);

    // pick largest mono color
    set<char> colors{'R', 'Y', 'B'};
    char largest = '.', medium = '.', smallest = '.';
    if (ct['R'] >= ct['Y'] && ct['R'] >= ct['B']) largest = 'R';
    else if (ct['Y'] >= ct['R'] && ct['Y'] >= ct['B']) largest = 'Y';
    else largest = 'B';
    colors.erase(largest);

    {
      // cout << "colors.size(): " << colors.size() << endl;;
      char l = *colors.begin(), r = *(++colors.begin());
      // cout << "l: " << l << " r: " << r << endl;
      if(ct[l] >= ct[r]) {
        medium = l; smallest = r;
      } else {
        medium = r; smallest = l;
      }
    }
    // cout << "largest: " << largest << " (" << ct[largest] << ") ";
    // cout << "medium: " << medium << " (" << ct[medium] << ") ";
    // cout << "smallest: " << smallest << " (" << ct[smallest] << ")" << endl;
    if(ct[largest] > (ct[smallest] + ct[medium])) {
      cout << "Case #" << CASE << ": IMPOSSIBLE" << endl;
      continue;
    }

    for(int i=0;i<ct[largest];i++) stall.push_back(largest);
    for(auto i=0; i<ct[medium]; i++) stall.insert(stall.begin() + (2*i) + 1, medium);
    for(auto i=0; i<ct[smallest]; i++) stall.insert(stall.end() - (2*i), smallest);
    cout << "Case #" << CASE << ": " << stall << endl;
  }
}
