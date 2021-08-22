#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
void solve() {
  // reading input
  int N = 100, M = 10000;
  string A[N];
  F0R(i, N) cin >> A[i];
  int cnt[M]; F0R(i, M) cnt[i] = 0;
  F0R(i, N) F0R(j, M) cnt[j] += A[i][j] - '0';

  // sort questions by easiness (descending)
  vpi easiness(M);
  F0R(i, M) easiness[i] = {cnt[i], i};
  sort(all(easiness));
  reverse(all(easiness));

  // bucket the questions into blocks of 200 (so 50 buckets)
  // buck[j] maps question #j (in the input, j = easiness[i].s) to j's bucket
  // There are 50 buckets, M/50 = 200
  int buck[M]; F0R(i, M) buck[easiness[i].s] = i/(M/50);
  ld corr[N];
  F0R(i, N) {
    int num[50]; // num[i] = number of 1s in bucket i
    F0R(j, 50) num[j] = 0;
    F0R(j, M) num[buck[j]] += A[i][j] - '0';
    ld bestNot = 1e10, bestCheat = 1e10;
    corr[i] = 0;
    for (ld prob = -3; prob < 3; prob += .06) {  // 0.06 = 6/100
      ld a = 0, b = 0;
      F0R(j, 50) {
        ld cur = -3 + .06; // midpoint of first bucket
        cur += j * .12;
        ld p = exp(cur-prob); p = 1/(1+p); // cur-prob = estimated P_i?
        a += (p*200-num[j])*(p*200-num[j]); // p*200 = expected # of 1s, so this is bucket error
        ld p2 = exp(cur-prob); p2 = 0.5+0.5/(1+p2); // p = odds of correct if cheating
        b += (p2*200-num[j])*(p2*200-num[j]); // p*200 = expected # of 1s if cheating
      }
      ckmin(bestNot, a);
      ckmin(bestCheat, b);
    }
    /*F0R(j, 50) {
      if (i == 47 || i == 58) {
        cout << num[j] << " ";
      }
    }
    cout << nl;*/
    //cout << bestNot << " " << bestCheat << " " << i << nl;
    corr[i] = log(bestCheat) - log(bestNot);
    //corr[i] = bestCheat;
  }
  int ans = 0;
  FOR(i, 1, N) {
    if (corr[ans] > corr[i]) ans = i;
  }
  cout << ans+1 << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
  int T; cin >> T;
  int P; cin >> P;
  FOR(i, 1, T+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343

