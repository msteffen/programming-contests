#include <algorithm>
#include <iostream>

using namespace std;

typedef long long lli;

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    lli D, N;
    cin >> D >> N;
    double max_time = 0;
    for(lli i=0;i<N;i++) {
      lli K, S;
      cin >> K >> S;
      double time = ((double) (D-K))/((double) S);
      max_time = max(max_time, time);
    }
    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);
    cout << "Case #" << CASE << ": " << (((double) D)/max_time) << endl;
  }
}
