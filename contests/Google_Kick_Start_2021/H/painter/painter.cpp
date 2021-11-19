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

template<class T> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
template<class T> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

template<class T, class U>
ostream& operator<<(ostream& o, const pair<T, U>& p) {
  o << "(" << p.f << ", " << p.s << ")";
  return o;
}

template<class T>
ostream& operator<<(ostream& o, const V<T>& v) {
  o << "[";
  FOR(i,0,sz(v)) {
    if(i>0) o<<",";
    o<<v[i];
  }
  o<<"]";
  return o;
}

template <class T, template<class U> class S>
ostream& operator<<(ostream& o, const S<T>& xs) {
  o << "{";
  bool first(true);
  RANGE(x,xs) {
    if (!first) {
      o<<",";
    } else {
      first=false;
    } 
    o << x;
  }
  o << "}";
  return o;
}

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << "L" << __LINE__ << ": "

bool in(int c, char inc) {
  switch (inc) {
    case 'U':
      return false;
    case 'R':
      return c == 0;
    case 'Y':
      return c == 1;
    case 'B':
      return c == 2;
    case 'O':
      return c == 0 || c == 1;
    case 'P':
      return c == 0 || c == 2;
    case 'G':
      return c == 1 || c == 2;
    case 'A':
      return true;
  }
  throw runtime_error("unreachable code");
}

void solve() {
  int N; string P;
  cin >> N >> P;
  vector<int> count{0,0,0}, last{-2,-2,-2};
  // cout << endl;
  for(int d=0;d<3;d++) {
    // cout << d << ": ";
    for(int i=0;i<sz(P);i++) {
      char c = P[i];
      if(in(d,c)) {
        // cout << "*";
        if(last[d] != (i-1)) count[d]++;
        last[d]=i;
      } else {
        // cout << " ";
      }
    }
    // cout << endl;
  }
  cout << count[0]+count[1]+count[2] << endl;
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
