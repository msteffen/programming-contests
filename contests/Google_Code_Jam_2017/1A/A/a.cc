#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int R = 0, C = 0;
vector<string> cake(25, "?????????????????????????");

void print_whole_cake() {
  for(int i=0;i<25;i++) {
    for(int j=0;j<25;j++) {
      cout << cake[i][j];
    }
    cout << endl;
  }
}

void print_cake() {
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      cout << cake[i][j];
    }
    cout << endl;
  }
}

void clear_cake() {
  for(int i=0;i<25;i++) {
    memset((char*)cake[i].data(),'?',25);
  }
}

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    clear_cake();
    cin >> R >> C;
    for(int i=0;i<R;i++) cin >> cake[i];

    // 1) grow regions right
    for(int i=0;i<R;i++) {
      for(int j=1;j<C;j++) {
        if(cake[i][j] == '?') {
          cake[i][j] = cake[i][j-1];
        }
      }
    }
    // print_cake();
    // cout << "-------------------------" << endl;

    // 1) grow regions left
    for(int i=0;i<R;i++) {
      for(int j=C-2;j>=0;j--) {
        if(cake[i][j] == '?') {
          cake[i][j] = cake[i][j+1];
        }
      }
    }
    // print_cake();
    // cout << "-------------------------" << endl;


    // 2) Grow all regions downward
    for(int i=0;i<C;i++) {
      for(int j=1;j<R;j++) {
        if(cake[j][i] == '?') {
          cake[j][i] = cake[j-1][i];
        }
      }
    }
    // print_cake();
    // cout << "-------------------------" << endl;

    // 3) Grow top regions upwards
    for(int i=0;i<C;i++) {
      for(int j=R-2;j>=0;j--) {
        if(cake[j][i] == '?') {
          cake[j][i] = cake[j+1][i];
        }
      }
    }

    cout << "Case #" << CASE << ": " << endl;
    print_cake();
  }
}
