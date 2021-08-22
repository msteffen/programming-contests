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

int N;
void solve() {
    vi A;
    cout << "1 2 3" << endl;
    int X; cin >> X;
    if (X == -1) return;
    if (X == 1) {
        A.pb(2); A.pb(1); A.pb(3);
    } else if (X == 2) {
        A.pb(1); A.pb(2); A.pb(3);
    } else {
        A.pb(1); A.pb(3); A.pb(2);
    }

    FOR(i, 4, N+1) {
        int lo = 0, hi = sz(A);
        while (lo < hi) {
            int l = (2*lo+hi)/3;
            int r = (2*hi+lo)/3;
            if (r == sz(A)) {
                r--;
                
            }
            if (r == l) {
                if (l > 0) {
                    l--;
                } else {
                    r++;
                }
            }
            cout << A[l] << " " << A[r] << " " << i << endl;
            cin >> X;
            if (X == -1) return;
            if (X == A[l]) {
                hi = l;
            } else if (X == A[r]) {
                lo = r+1;
            } else {
                lo = l+1; hi = r;
            }
        }
        auto it = A.begin() + lo;
        A.insert(it, i);
    }

    F0R(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    cin >> X;
    if (X == -1) return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    int Q;
    cin >> N >> Q;
    FOR(i, 1, T+1) {
        solve();
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343

