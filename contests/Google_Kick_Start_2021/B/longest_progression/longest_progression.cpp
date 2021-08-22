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
#define dbg if(__LOCAL__ == 0) {} else cout <<  "L" << __LINE__ << ": "

void solve() {
  ll N; cin >> N;
  V<ll> L(N, 0);
  FOR(i,0,N) cin >> L[i];
  dbg <<  endl << L << endl;
  V<V<pair<int,ll>>> DP(N, V<pair<int,ll>>(2));
  // DP[i][s] = best factor/length of seq ending at i, using s skips
  DP[0][0] = DP[0][1] = mp(1, INT_MAX);
  DP[1][0] = DP[1][1] = mp(2, L[1]-L[0]);
  int best = 1;
  FOR(i,2,N) {
    ll d = L[i]-L[i-1];
    // no skips up to i -- one way to do it
    DP[i][0] = mp(d == DP[i-1][0].s ? (DP[i-1][0].f+1) : 2, d);

    // one skip up to i -- three ways
    pair<ll,ll> skip_old = mp(
        d == DP[i-1][1].s ? (DP[i-1][1].f+1) : 2, d
    );
    pair<ll,ll> skip_this = mp(DP[i-1][0].f+1, DP[i-1][0].s);
    ll d2 = L[i] - L[i-2];
    if(d2%2 == 0) {
      d2 /= 2;
      pair<ll,ll> skip_prev = mp(d2 == DP[i-2][0].s ? (DP[i-2][0].f+2) : 2, d2);
      if(skip_prev.f > DP[i][1].f) {
        DP[i][1] = skip_prev;
      }
    }
    DP[i][1] = os_l.f > os_r.f ? os_l : os_r;
    DP[i][1] = mp(DP[i-1][0].s, DP[i-1][0].f+1);
    pair<ll,ll> os_l = mp(DP[i-2][0].f+1, DP[i-1][1].s); // skip this
    // don't skip this but skip somewhere earlier
    pair<ll,ll> os_r = mp(d == DP[i-1][1].s ? (DP[i-1][1].f+1) : 2, d);
    DP[i][1] = os_l.f > os_r.f ? os_l : os_r;
    dbg << DP << endl;
    best = max(best, max(DP[i][0].f, DP[i][1].f));
  }
  cout << best << endl;
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
