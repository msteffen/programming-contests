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
#define dbg if(__LOCAL__ == 0) {} else cout << __FILE__ << ":" <<  __LINE__ << ": "

void solve() {
 int len;
 string str;
 cin >> len >> str;
 V<int> lens(sz(str), 1);
 FOR(i,1,sz(str)) {
     if(str[i]>str[i-1]) lens[i]=lens[i-1]+1;
 }
 FOR(i,0,sz(lens)) {
   cout << (i==0?"":" ") << lens[i];
 }
 cout <<endl;
}
// This implements longest-increasing subsequence, which is a very nice DP
// algorithm but not what the problem asked for -_-
// void solve() {
//   int len;
//   string str;
//   cin >> len >> str;
//   V<char> last_of_length = {str[0]};
//   V<int> longest_seq(sz(str), 1);
//   last_of_length[0] = str[0];
//   FOR(i,1,sz(str)) {
//     if(str[i] < last_of_length[0]) {
//       last_of_length[0] = str[i];
//       longest_seq[i] = 1;
//       continue;
//     }
//     int l = (lb(all(last_of_length), str[i]) - last_of_length.begin());
//     dbg << "str[i]: " << str[i] << " l: " << l << endl;
//     longest_seq[i] = l+1;
//     if(l==sz(last_of_length)) {
//       last_of_length.pb(str[i]);
//       dbg << last_of_length << endl;
//       dbg << longest_seq << endl;
//       continue;
//     }
//     dbg << last_of_length << endl;
//     dbg << longest_seq << endl;
//     if(last_of_length[l] > str[i]) {
//       last_of_length[l] = str[i];
//     }
//   }
//   FOR(i,0,sz(longest_seq)) {
//     cout << (i==0?"":" ") << longest_seq[i];
//   }
//   cout <<endl;
// }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
  int __CASES__; cin >> __CASES__;
  FOR(i, 1, __CASES__+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
	return 0;
}
