#include<bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i<CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))

using namespace std;

int main(int argc, char* argv[]) {
  int ZZ;
  cin >> ZZ;
  FOR(Z,0,ZZ) {
    cout << "Case #" << (Z+1) << ":" << endl;
    int N;
    cin >> N;
    string instr, outstr;
    cin >> instr >> outstr;
    vector<vector<bool>> P(N, vector<bool>(N, true));
    FOR(d,1,N) {
      FOR(i,0,N-d) {
        P[i][i+d] = P[i][i+d-1] && (outstr[i+d-1]=='Y') && (instr[i+d]=='Y');
      }
      FOR(i,d,N) {
        P[i][i-d] = P[i][i-d+1] && (outstr[i-d+1]=='Y') && (instr[i-d]=='Y');
      }
    }
    FOR(i,0,N) {
      FOR(j,0,N) cout << (P[i][j]?"Y":"N");
      cout << endl;
    }
  }
}
