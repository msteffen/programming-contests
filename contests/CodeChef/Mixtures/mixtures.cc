#include<bits/stdc++.h>

#define FOR(i,l,r) \
  for (int i = (l); i < (r); i++)

constexpr int MAX_I = 1<<((sizeof(int)*8)-2);

int N;

// std::ostream& operator<<(std::ostream& o, int* A) {
//   o << "[";
//   for(int i=0;i<N+1;i++) o << (i==0?"":", ") << A[i];
//   o << "]";
//   return o;
// }

using namespace std;

int P[100]; // Potions
int S[101]; // Partial sums; S[a] = sum( P[i] | i <= a )
int DP[101][101]; // DP[a][b] = min smoke to combine potions in range [a,b)

int m(int x, int m) {
  return ((x%m)+m)%m;
}

int main(int argc, char *argv[]) {
  while (cin >> N) {
    // Set P
    memset(P, 0, sizeof(int)*N);
    FOR(i,0,N) cin >> P[i];
    // Set S
    memset(S, 0, sizeof(int)*(N+1));
    FOR(i,1,N+1) S[i] = m(S[i-1]+P[i-1],100);
    // cout << "S: " << S << endl;

    FOR(i,0,N+1) memset(DP[i], 0, sizeof(int)*(N+1));
    // cout << "N: " << N << endl;
    FOR(s,2,N+1) { // induction on sz of interval (2..N)
      FOR(l,0,N-s+1) {
        int r=l+s;
        DP[l][r] = MAX_I;
        // cout << "---" << endl;
        FOR(mid,l+1,r) {
          // cout << "DP[" << l << "][" << r << "] ?= DP[" << l << "][" << mid << "] + DP[" << mid << "][" << r << "] + (S[" << mid << "]-S[" << l << "])*(S[" << r << "]-S[" << mid << "])" << endl;
          int smoke = DP[l][mid]+DP[mid][r]+(
                m(S[mid]-S[l],100)*m(S[r]-S[mid], 100)
            );
          DP[l][r]=min(smoke,DP[l][r]);
        }
      }
    }
    cout << DP[0][N] << endl;
  }
}
