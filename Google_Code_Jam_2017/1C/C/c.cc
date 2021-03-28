#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef unsigned long long ull;
typedef long double d;

int ones(ull n) {
  ull s = n;
  s=(s & 0X5555555555555555ULL) + ((s>>1) & 0X5555555555555555ULL);
  s=(s & 0X3333333333333333ULL) + ((s>>2) & 0X3333333333333333ULL);
  s=(s & 0X0F0F0F0F0F0F0F0FULL) + ((s>>4) & 0X0F0F0F0F0F0F0F0FULL);
  s=(s & 0X00FF00FF00FF00FFULL) + ((s>>8) & 0X00FF00FF00FF00FFULL);
  s=(s & 0X0000FFFF0000FFFFULL) + ((s>>16) & 0X0000FFFF0000FFFFULL);
  s=(s & 0X00000000FFFFFFFFULL) + ((s>>32) & 0X00000000FFFFFFFFULL);
  return (int) s;
}

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    int N, K;
    cin >> N >> K;
    d U;
    cin >> U;
    vector<d> P(N, 0);
    for(int i=0;i<N;i++) cin >> P[i];
    vector<d> h(N, 0); // , t(N, 0);
    // d total_p;
    for(ull s=0;s<(1<<N);s++) {
      if(ones(s) < K) continue;
      d newp = 0;
      for(int i=0;i<N;i++) {
        if(((s>>i) & 1) > 0) {
          newp *= P[i];
        }/* else {
          newp *= (1-P[i]);
        }*/
      }
      //total_p += newp
      for(int i=0;i<N;i++) {
        if(((s>>i) & 1) > 0) {
          h[i] += newp;
        } /*else {
          t[i] += newp;
        }*/
      }
    }

    vector<int> p_sorted(N, 0);
    for(int i=0;i<N;i++) p_sorted[i] = i;
    sort(p_sorted.begin(), p_sorted.end(),
        [&h](int l, int r) -> bool { return h[l] > h[r]; });
    for(int i=0;i<N;i++) {
      d delta = min(U, 1e0L);
      P[i] += delta;
      U -= delta;
      if(U < 1e-6) break;
    }
    d total_p = 0;
    for(ull s=0;s<(1<<N);s++) {
      if(ones(s) < K) continue;
      d newp = 0;
      for(int i=0;i<N;i++) {
        if(((s>>i) & 1) > 0) {
          newp *= P[i];
        }
      }
      total_p += newp;
    }
    cout.precision(numeric_limits<d>::max_digits10);
    cout << "Case #" << CASE << ": " << total_p << endl;
  }
}
