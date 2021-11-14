#include <bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i!=CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))
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

ostream& operator<<(ostream& o, const set<int>& s) {
  o << s.size() << ".";
  RANGE(i,s) {
    o << '{' << i << '}';
  }
  return o;
}

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << "L" << __LINE__ << ": "

struct event {
  int i, h, s, e;
};

ostream& operator<<(ostream& o, const event& e) {
  o << '[' << e.i << "/" << e.h << ',' << e.s << ',' << e.e << ']';
  return o;
}

istream& operator>>(istream& i, event& e) {
  i >> e.h >> e.s >> e.e;
  e.e++; // make events right-open
  return i;
}

void solve() {
  int D(0), N(0), K(0);
  cin >> D >> N >> K;
  dbg << "K:" << K << endl;
  V<event> events(N, event());
  FOR(i,0,N) {
    cin >> events[i];
  }
  sort(all(events), [](const event& l, const event& r) -> bool { return l.h < r.h; });
  FOR(i,0,N) events[i].i = i;

  V<event> starts(events), ends(events);
  dbg << events << endl;
  sort(all(starts), [](const event& l, const event& r) -> bool { return l.s < r.s; });
  sort(all(ends), [](const event& l, const event& r) -> bool { return l.e < r.e; });
  set<int> running;
  int s_i(0), e_i(0), h(0), max_happiness(0);
  set<int>::iterator kth = running.end();
  while(s_i < starts.size() && e_i < ends.size()) {
    int day(min(starts[s_i].s, ends[e_i].e)), h_today(0);
    dbg << "day " << day << endl;
    while (s_i < starts.size() && starts[s_i].s == day) {
      const event& e = starts[s_i]; s_i++;
      running.insert(e.i);
      dbg << "inserting " << e << endl;
      if (running.size() == K) kth = (--running.end());
      if (running.size() <= K || e.h > events[*kth].h) {
        dbg << "h(" << h << ") += " << e.h << endl;
        h += e.h;
      }
      if (running.size() > K && e.h > events[*kth].h) {
        dbg << "h(" << h << ") -= " << events[*kth].h << endl;
        h -= events[*kth].h;
        kth--;
      }
    }
    while (e_i < ends.size() && ends[e_i].e == day) {
      const event& e = ends[e_i]; e_i++;
      running.erase(e.i);
      dbg << "erasing " << e << endl;
      if (running.size() < K || e.h > events[*kth].h) {
        dbg << "h(" << h << ") -= " << e.h << endl;
        h -= e.h;
      }
      if (running.size() >= K && e.h >= events[*kth].h) {
        kth++;
        dbg << "h(" << h << ") += " << events[*kth].h << endl;
        h += events[*kth].h;
      }
    }
    dbg << "daily happiness: " << h << "|" << running << endl;
    max_happiness = max(max_happiness, h);
  }
  cout << max_happiness << endl;
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
