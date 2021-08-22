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

template<class K, class V>
ostream& operator<<(ostream& o, map<K,V> m) {
  o << "{";
  bool first = true;
  for(const auto& e : m) {
    if(first) {
      o<<", ";
      first = false;
    }
    o<<e.f << ":" << e.s;
  }
  o<<"}";
  return o;
}

template<class T>
ostream& operator<<(ostream& o, V<T> v) {
  o << "[";
  bool first = true;
  for(const auto& x : v) {
    if(first) {
      o<<", ";
      first = false;
    }
    o<<x;
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

void solve() {
  cout << "STARTING" << endl;
  int N, Q; cin >> N >> Q;
  V<map<int,pair<ll,ll>>> neighbors(N);
  FOR(i,0,N-1) {
    int v1, v2; ll a, w; cin >> v1 >> v2 >> a >> w;
    --v1; --v2;
    neighbors[v1][v2] = mp(w, a);
    neighbors[v2][v1] = mp(w, a);
    cout << neighbors << endl;
  }
  V<pair<int,pair<ll,ll>>> wa(N);
  deque<pair<int, int>> queue;
  for(const auto& entry : neighbors[0]) {
    queue.emplace_back(1, entry.f);
  }
  while(sz(queue) > 0) {
    auto next = queue.front(); queue.pop_front();
    wa[next.s] = mp(next.f, move(neighbors[next.f][next.s]));
    for(const auto& entry : neighbors[next.s]) {
      if(entry.f == next.f) continue;
      queue.emplace_back(next.s, entry.f);
    }
  }
  FOR(i,0,Q) {
    int c; ll w; cin >> c >> w;
    --c;
    bool has_toll = false;
    ll toll_gcd = 0;
    while(c) {
      if(w>=wa[c].s.f) {
        toll_gcd = std::gcd(toll_gcd, wa[c].s.s);
      }
      c = wa[c].f;
    }
    cout << " "  << toll_gcd;
  }
  cout << endl;
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);    
  int __CASES__; cin >> __CASES__;
  FOR(i, 1, __CASES__+1) {
    cout << "Case #" << i << ":";
    solve();
  }
	return 0;
}
