#include<bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i<CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))

using namespace std;

map<int,int> dp;
vector<pair<int,int>> trees(800000, make_pair(0,0)); // vector of (posn, height)

int main(int argc, char* argv[]) {
  int ZZ;
  cin >> ZZ;
  FOR(Z,0,ZZ) {
    dp.clear();
    trees.clear();
    int p_i, h_i;
    int N;
    cin >> N;
    FOR(i,0,N) {
      cin >> p_i >> h_i;
      trees.emplace_back(p_i, h_i);
    }

    // sort by start posn
    sort(trees.begin(), trees.end());
    int best(0);
    FOR(i,0,N) {
      p_i = trees[i].first;
      h_i = trees[i].second;
      // tree falls right -- do first, before dp[p_i] is updated
      dp[p_i+h_i] = max(dp[p_i+h_i], dp[p_i]+h_i);

      // tree falls left
      dp[p_i] = max(dp[p_i], dp[p_i-h_i] + h_i);
      best = max(best, max(dp[p_i+h_i], dp[p_i]));
    }
    cout << "Case #" << (Z+1) << ": " << best << endl;
  }
}
