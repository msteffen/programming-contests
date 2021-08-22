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

int ask(int a, int b, int c) {
	printf("%d %d %d\n", a, b, c); fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

void solve() {
	int T, N, Q;
	scanf("%d%d%d", &T, &N, &Q);
	for(int t=1;t<=T;t++) {
		int v = ask(1, 2, 3);
		vector <int> w(3);
		w[1] = v;
		w[2] = v % 3 + 1;
		w[0] = w[2] % 3 + 1;
		for(int i=4;i<=N;i++) {
			int l = 0, h = szz(w);
			while(l < h) {
				int n = h - l + 1;
				if(n == 2) {
					if(l == 0) {
						int rv = ask(w[0], w[1], i);
						if(rv == i) l = 1;
						else h = 0;
					}
					else {
						int rv = ask(w[0], w[l], i);
						if(rv == i) h = l;
						else l = h;
					}
					break;
				}
				int m1 = l + n / 3;
				int m2 = l + (2*n) / 3;
				int rv = ask(w[m1-1], w[m2-1], i);
				if(rv == i) l = m1, h = m2 - 1;
				else if(rv == w[m1-1]) h = m1 - 1;
				else l = m2;
			}
			w.insert(w.begin() + l, i);
		}
		for(int e : w) printf("%d ", e); puts("");
	}
	int xt; scanf("%d", &xt);
}

int main() {
	int T = 1; //scanf("%d", &T);
	for(int t=1;t<=T;t++) {
	//	printf("Case #%d: ", t);
		solve();
	}
	return 0;
}