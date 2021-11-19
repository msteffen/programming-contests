#include <bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i!=CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))
#define RANGE(x,xs) for (auto& x : (xs))
 
using namespace std;
 
using ll = long long;
using ld = long double;
using cd = complex<ld>;

using pi = pair<int, int>;
using pl = pair<ll,ll>;
using pd = pair<ld,ld>;

using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

using vpi = vector<pi> ;
using vpl = vector<pl> ;
using vcd = vector<cd> ;

template<class T> using V = vector<T>; 
template<class T> using PR = pair<T,T>; 
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound // lb(l, r, x) = first n in [l,r) s.t. !(n < x) (n >= x)
#define ub upper_bound // ub(l, r, x) = first n in [l,r) s.t. n > x

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << "L" << __LINE__ << ": "

ll d(char a, char b) {
  if (b < a) {
    char t = b;
    b = a;
    a = t;
  }
  return min(b-a, (a-'a') + ('z'-b) + 1);
}

void solve() {
  string S, F;
  cin >> S >> F;
  ll ops = 0;
  RANGE(c, S) {
    ll dist = 0;
    if (sz(F) == 1) {
      dist = d(*F.begin(), c);
    } else {
      auto b = lb(all(F), c);
      if (b == F.end() || b == F.begin()) {
        dist = min(d(*(F.end()-1),c),d(*F.begin(),c));
      } else {
        dist = min(d(*b,c),d(*(b-1),c));
      }
    }
    ops += dist;
  }
  cout << ops << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
  int __CASES__; cin >> __CASES__;
  FOR(i, 1, __CASES__+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
	return 0;
}

