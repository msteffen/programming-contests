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

// examples: sort(all(vec)) reverse(all(vec));
#define all(x) x.begin(), x.end()
#define ins insert

#ifndef __LOCAL__
  #define __LOCAL__ 0
#endif
#define dbg if(__LOCAL__ == 0) {} else cout << "L" << __LINE__ << ": "

void solve() {
  int N,A,B; cin >> N >> A >> B;
  deque<pair<V<int>,V<int>>> q;
  {
    V<int> counts(N);
    V<int> excess(N);
    counts.reserve(2*N);
    FOR(i,0,N) cin >> counts[i];
    dbg << counts << endl;
    q.pb(mp(counts, excess));
  }
  while(!q.empty()) {
    const auto& pr = q.front();
    q.pop_front();
    V<int> counts = pr.f; V<int> excess = pr.s;
    dbg << counts << endl;
    dbg << excess << endl;
    bool any = false;
    FOR(i,1,sz(counts)) {
      dbg << "i:" << i << endl;
      if(counts[i]>0 && counts[i-1]>0) {
        if((i+1)>=sz(counts)) {counts.pb(0); excess.pb(0);}
        int units = min(counts[i],counts[i-1]);
        dbg << units << " units from (" << i << "," << i-1 << ") -> " << i+1 << endl;
        counts[i+1] += units;
        counts[i] -= units;
        counts[i-1] -= units;
        any = true;
        dbg << "new: " << counts << endl;
      }
    }
    if(!any) {
      dbg << "halving.." << endl;
      int maxarg = -1, minarg = sz(counts);
      FOR(i,sz(counts)-1,-1) {
        dbg << "counts[" << i << "]-excess["<<i<<"] = " << (counts[i]-excess[i]) << endl;
        if((counts[i]-excess[i])>0) {
          minarg = min(i, minarg);
          dbg << "i:" << i << " maxarg:" << maxarg << " max:" << max(i,maxarg) << endl;
          maxarg = max(i, maxarg);
        }
      }
      dbg << "minarg:" << minarg << " maxarg:" << maxarg << " count:" << (counts[minarg]-excess[minarg]) << endl;
      if((minarg==maxarg)&&(counts[minarg]-excess[minarg])==1) {
        cout << (minarg+1) << endl;
        break;
      }
      if((minarg+1)>=sz(counts)) {counts.pb(0); excess.pb(0);}
      if((minarg+2)>=sz(counts)) {counts.pb(0); excess.pb(0);}
      int need = (counts[minarg]+1)/2;
      counts[minarg+2]+=need;
      if(minarg>0) {
        counts[minarg-1]+=counts[minarg];
        excess[minarg-1]+=counts[minarg];
      }
      counts[minarg] = 0;
    }
  }
}

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);    
  int __CASES__; cin >> __CASES__;
  FOR(i, 1, __CASES__+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
	return 0;
}
