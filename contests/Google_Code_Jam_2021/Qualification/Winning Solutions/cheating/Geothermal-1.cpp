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
    int N = 100, M = 10000;
    string A[N];
    F0R(i, N) cin >> A[i];
    int cnt[M]; F0R(i, M) cnt[i] = 0;
    F0R(i, N) F0R(j, M) cnt[j] += A[i][j] - '0';
    ld corr[N];
    ld cAve = 0; F0R(i, M) cAve += cnt[i];
    cAve /= M;
    F0R(i, N) {
        ld aAve = 0;
        F0R(j, M) {
            aAve += A[i][j] - '0';
        }
        aAve /= N;
        ld num = 0;
        ld den1 = 0, den2=0;
        F0R(j, M) {
            ld a = A[i][j] - '0';
            num += (a-aAve)*(cnt[j]-cAve);
            den1 += (a-aAve)*(a-aAve);
            den2 += (cnt[j]-cAve)*(cnt[j]-cAve);
        }
        corr[i] = num / sqrt(den1 * den2);
    }
    int ans = 0;
    FOR(i, 1, N) {
        if (corr[i] < corr[ans]) ans = i;
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

