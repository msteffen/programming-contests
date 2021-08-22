#include <bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) long long CAT(__L_, __LINE__, __) = (l); long long CAT(__R_, __LINE__, __) = (r); for(long long i=CAT(__L_, __LINE__, __);i<CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))
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
#define dbg if(__LOCAL__ == 0) {} else cerr << "L" << __LINE__ << ": "

// construct a trivial random generator engine from a time-based seed:
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);

int main() {
	// ios_base::sync_with_stdio(0); cin.tie(0);
  ll T, N, B, P; cin >> T >> N >> B >> P;
  FOR(testcase,0,T) {
    V<int> tower(N);
    FOR(i,0,N*B) {
      ll next; cin >> next;
      if(next == -1) {
        return 0; // failure
      }
      int choice;
      V<double> tower_score(N);
      double sum;
      {
        FOR(t,0,N) {
          double size = 0.0;
          if(tower[t] < B) {
            size = round(abs(
                (((double)next)/(9.0)) -
                (((double)tower[t])/((double)(B-1)))
            )
          }
          if(t == 0) tower_score[t] = size;
          else tower_score[t] = tower_score[t-1]+size;
          sum += size;
        }
        uniform_int_distribution<int> dist(0,tower_score[N-1]-1);
        double dice = dist(generator);
        FOR(t,0,N) {
          if(dice < tower_score[t]) {
            choice = t;
            break;
          }
        }
        // dbg << dice << " from " << tower_score << " -> " << choice << endl;
      }
      cout << (choice+1) << endl;
      // dbg << next << " -> " << tower << "[" << choice << "]" << endl;
      ++tower[choice];
    }
  }
  int success; cin >> success;
  // dbg << success << endl;
  return 0;
}
