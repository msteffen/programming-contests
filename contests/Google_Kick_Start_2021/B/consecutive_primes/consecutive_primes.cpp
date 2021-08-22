#include <bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i<CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))
#define RANGE(a,x) for (auto& a : x)
 
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
#define lb lower_bound // lb(l, r, x) = first n in [l,r) s.t. n >= x
#define ub upper_bound // ub(l, r, x) = first n in [l,r) s.t. n > x

template<class T> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
template<class T> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }

template<class T, class U>
ostream& operator<<(ostream& o, pair<T, U> p) {
  o << "(" << p.f << ", " << p.s << ")";
  return o;
}

template<class T>
ostream& operator<<(ostream& o, V<T> v) {
  o << "[";
  FOR(i,0,sz(v)) {
    if(i>0) o<<", ";
    o<<v[i];
  }
  o<<"]";
  return o;
}

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << "L" << __LINE__ << ": "

V<ll> P;
V<ll> PP;
void solve() {
  ll Z; cin >> Z;
  auto l = ub(all(PP), Z);
  cout << *(l-1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
  int __CASES__; cin >> __CASES__;
  P.reserve(1<<30);
  PP.reserve(1<<30);
  P.pb(2);
  P.pb(3);
  P.pb(5);
  P.pb(7);
  P.pb(11);
  P.pb(13);
  FOR(i, 17, 10000001) {
    FOR(j,0,100001) {
      if(P[j]*P[j] > i) {
        P.pb(i);
        break;
      }
      if(i%P[j] == 0) break;
    }
  }
  FOR(i,1,sz(P)) PP.pb(P[i-1]*P[i]);
  FOR(i, 1, __CASES__+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
	return 0;
}
