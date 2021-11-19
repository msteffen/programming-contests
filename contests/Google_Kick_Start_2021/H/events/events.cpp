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

#define TRU 1000000

ll m(ll l, ll r) {
  return (l*r)/TRU;
}

V<int> Par;
V<int> Pinv;
V<ll> Prob;
V<ll> T;
V<ll> F;
int meet(int u, int v) {
  V<int> path = vector(0,0);
  for(int i=u;i!=1;i=P[i]) { path.pb(i); }
  reverse(all(path));
  for(int i=v;i!=1;i=P[i]) {
    if(binary_search(all(path),i)) return i;
  }
  return 1;
}

void solve() {
  int N, Q; cin >> N >> Q;
  Par = vector<int>(N+1, 0);
  Pinv = vector<int>(N+1, 0);
  Prob = vector<int>(N+1, 0);
  T = vector<ll>(N+1, 0LL);
  F = vector<ll>(N+1, 0LL);
  cin >> Prob[1];
  FOR(i,2,N+1) {
    if (i > 0) {
      cin >> Par[i] >> T[i] >> F[i];
    }
    Pinv[P[i]] = i;
    Prob[i] = m(T[i],Prob[P[i]])+m(F[i],(TRU-Prob[P[i]]))
  }
  cout << Par << endl;
  FOR(i,0,Q) {
    int u, v; cin >> u >> v;
    cout << endl << i << ": meet(" << u << "," << v << ") = " << meet(u,v) << endl;
  }
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
