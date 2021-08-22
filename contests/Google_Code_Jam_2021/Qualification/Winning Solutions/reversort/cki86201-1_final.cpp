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
	int n, a[110];
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", a + i);
	int ans = 0;
	for(int i=1;i<n;i++) {
		int j = (int)(min_element(a + i, a + n + 1) - a);
		ans += j - i + 1;
		reverse(a + i, a + j + 1);
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}