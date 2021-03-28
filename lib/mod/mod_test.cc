#include<iostream>
#include<sstream>
#include<vector>
#include<utility>
#include<chrono>

#define BASE 1000000007LL
#include "mod.h"

using namespace std;

vector<pair<string,void(*)()>> __tests__;

class __tests_adder__ {
  public:
    __tests_adder__(string name, void(*f)()) {
      __tests__.push_back(make_pair(name, f));
    }
};

#define TEST(name) \
void __test__##name(); \
__tests_adder__ __##name##_adder__(#name, __test__##name); \
void __test__##name()

// Latest run: 1026.25ms
TEST(inverses_custom_type) {
  for(long long i=1LL; i<BASE/500; i++) {
    if(i%100000 == 0) cout << i << endl;
    mi o = mi(i)/i;
    if(o._i != 1LL) {
      stringstream error;
      error << i << "^2 == " << o._i << ", not 1";
      throw runtime_error(error.str());
    }
  }
}

// Latest run: 766.634ms
TEST(inverses_no_redirection) {
  for(long long i=1LL; i<BASE/500; i++) {
    if(i%100000 == 0) cout << i << endl;
    ll o(mdiv(i,i));
    if(o != 1LL) {
      stringstream error;
      error << i << "^2 == " << o << ", not 1";
      throw runtime_error(error.str());
    }
  }
}

// Latest run: 710.033ms
TEST(inverses_no_recursion) {
  for(long long i=1LL; i<BASE/500; i++) {
    if(i%100000 == 0) cout << i << endl;
    ll o(fmdiv(i,i));
    if(o != 1LL) {
      stringstream error;
      error << i << "^2 == " << o << ", not 1";
      throw runtime_error(error.str());
    }
  }
}


int main(int argc, char* argv[]) {
  for(const auto& p : __tests__) {
    chrono::duration<double, milli> dur;
    try {
      auto t_start(chrono::high_resolution_clock::now());
      p.second();
      auto t_stop(chrono::high_resolution_clock::now());
      dur = t_stop-t_start;
    } catch(const exception& e) {
      cout << "[FAIL] " << p.first << endl << "  " << e.what() << endl << endl;
    }
    cout << "[PASS] " << p.first << " " << dur.count() << "ms" << endl << endl;
  }
}
