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

char In[110][10010];
using FL = double;
FL y[10010];

void solve() {
	rep(i, 100) scanf("%s", In[i]);
	rep(i, 10000) {
		int c = 0;
		rep(j, 100) if(In[j][i] == '1') ++c;
		if(c == 100) y[i] = -3;
		else if(c == 0) y[i] = 3;
		else {
			y[i] = log((FL)100/c - 1);
			if(y[i] < -3) y[i] = -3;
			if(y[i] > 3) y[i] = 3;
		}
	}
	FL x[100], s[100];
	rep(i, 100) {
		FL low = -3, high = 3;
		rep(j, 30) {
			FL mid = (low + high) * 0.5;
			FL vp = 0, vm = 0;
			int cp = 0, cm = 0;
			rep(k, 10000) {
				if(In[i][k] == '1') {
					++cp;
					vp -= log(1 + exp(mid - y[k]));
				}
				else {
					++cm;
					FL temp = exp(mid - y[k]);
					vm += log(temp / (1 + temp));
				}
			}
			vp /= cp; vm /= cm;
			if(vp > vm) low = mid;
			else high = mid;
		}
		x[i] = (low + high) * 0.5;
		FL sum = 0;
		rep(k, 10000) {
			FL temp = exp(x[i] - y[k]);
			if(In[i][k] == '1') sum += log(1 / (1 + temp));
			else sum += log(temp / (1 + temp));
		}
		s[i] = sum;
	}
	printf("%d\n", (int)(max_element(s, s+100) - s) + 1);
}

int main() {
	int T = 1; scanf("%d", &T);
	scanf("%*d");
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}