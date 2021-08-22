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

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-(a).begin()); }
template<class T> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-(a).begin()); }
template<class T, class U>
ostream& operator<<(ostream& o, V<pair<T,U>> v) {
  o << "[";
  FOR(i,0,sz(v)) {
    if(i>0) o<<", ";
    o<<"("<<v[i].f<<","<<v[i].s<< ")";
  }
  o<<"]";
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

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << __FILE__ << ":" <<  __LINE__ << ": "

void inc(V<pi> &vec, int n) {
  auto i = lwb(vec, mp(n,1));
  if(sz(vec)==i || vec[i].f != n) {
    vec.ins(vec.begin()+i,mp(n,1));
  } else {
    ++vec[i].s;
  }
}

void dec(V<pi> &vec, int n) {
  auto i = lwb(vec, mp(n,1));
  if(--vec[i].s == 0) vec.erase(vec.begin()+i);
}

void solve() {
  vpi X = {{1,1}, {2,1}, {4,1}};
  cout << X << endl;
  FOR(i,2,5) {
    inc(X, i);
    cout << X << endl;
  }
  FOR(i,2,5) {
    dec(X, i);
    cout << X << endl;
  }
  // reading input
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
