#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

void solve() {
	int n, c;
	scanf("%d%d", &n, &c);
	if(c < n - 1 || c > n * (n + 1) / 2 - 1) puts("IMPOSSIBLE");
	else {
		int x[110], a[110];
		for(int i=1;i<n;i++) x[i] = 1;
		int r = c - (n - 1);
		for(int i=1;i<n;i++) {
			int v = min(r, n + 1 - i - x[i]);
			x[i] += v;
			r -= v;
		}
		for(int i=1;i<=n;i++) a[i] = i;
		for(int i=n-1;i;i--) {
			int v = x[i] + i - 1;
			reverse(a + i, a + v + 1);
		}
		for(int i=1;i<=n;i++) printf("%d ", a[i]); puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}