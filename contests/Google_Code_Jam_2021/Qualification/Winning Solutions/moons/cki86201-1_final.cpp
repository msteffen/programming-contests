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
	int x, y;
	char c[1010];
	int dp[1010][2] = {};
	scanf("%d%d%s", &x, &y, c + 1);
	int n = (int)strlen(c + 1);
	const int INF = 1e9;
	dp[1][0] = dp[1][1] = INF;
	if(c[1] == 'C' || c[1] == '?') dp[1][0] = 0;
	if(c[1] == 'J' || c[1] == '?') dp[1][1] = 0;
	for(int i=2;i<=n;i++) {
		rep(j, 2) dp[i][j] = INF;
		rep(j, 2) rep(k, 2) {
			if(k == 0 && c[i] == 'J') continue;
			if(k == 1 && c[i] == 'C') continue;
			int add = 0;
			if(j != k) {
				if(k) add = x;
				else add = y;
			}
			dp[i][k] = min(dp[i][k], dp[i-1][j] + add);
		}
	}
	printf("%d\n", min(dp[n][0], dp[n][1]));
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}