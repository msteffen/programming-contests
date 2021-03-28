#include<bits/stdc++.h>
#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
// FOR(x, A, B) binds the variable to integers in [A, B) and iterates over the
// interval in that order (A may be >B, but in this case x will take the values
// A, A-1, A-2, ..., B+1)
#define FOR(i,l,r) \
  int CAT(__L_, __LINE__, __) = (l); \
  int CAT(__R_, __LINE__, __) = (r); \
  int CAT(__D_, __LINE__, __) = (CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)); \
  for(int i=CAT(__L_, __LINE__, __);\
        (CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)&&i<CAT(__R_, __LINE__, __))\
        ||(CAT(__L_, __LINE__, __)>CAT(__R_, __LINE__, __)&&i>CAT(__R_, __LINE__, __));\
      i+=CAT(__D_, __LINE__, __))


using namespace std;

ostream& operator<<(ostream& o, pair<int,unsigned long long> p) {
  o<<"("<<p.first<<","<<p.second<<")";
  return o;
}

ostream& operator<<(ostream& o, vector<pair<int,unsigned long long>> v) {
  o<<"[";
  for(const auto& p : v) o<<(p==*v.cbegin()?"":", ") << p;
  o<<"]";
  return o;
}

int N(0), M(0);
vector<int> P(1000000, 0); // P[i] = Price at stop i
// D is a monotonic list of index -> price  cutoffs (if (k,v) is in D, then
// you can get to indices <= k for price <=v).
// lower_bound(D.begin(), D.end(), i) lets us determine the minimum cost to get
// to index i in log time.
vector<pair<int,unsigned long long>> C;

int main(int argc, char* argv[]) {
  int ZZ;
  cin >> ZZ;
  FOR(Z,0,ZZ) {
    cin >> N >> M;
    P.clear();
    int p; // price
    FOR(i,0,N) {
      cin >> p;
      P.push_back(p);
    }
    C.clear(); C.emplace_back(M, 0); // Can go first M steps for free
    FOR(i,1,N) {
      // cout << C;
      // /* >>> */ if(i==0 || p==0) cout << endl;
      p = P[i];
      if(p==0) continue; // no gas
      // cout << p << endl;
      auto cost = lower_bound(C.begin(), C.end(), make_pair(i, 0ULL));
      // cout << make_pair(i, 0ULL) << " <? " << *(C.end()-1) << " " << (make_pair(i, 0ULL) < (*(C.end()-1))) << endl;
      // cout << " " << *cost << " end? = (" << (cost==C.end()) << ")" << endl;
      if(cost==C.end()) break; // impossible to get to i--no path to end
      pair<int, unsigned long long> n(i+M, cost->second+p);
      // cout << " " << n << endl;
      auto p=C.rbegin();
      while(p!=C.rend() && p->second>=n.second) p++;
      // This is the right arithmetic b/c [C.rbegin(), p) *is* right-open, even
      // though it's  backwards. It contains elements that are too expensive
      // (there's a cheaper path), and p is the first element that's not too
      // expensive
      C.resize(C.size()-(p-C.rbegin()));
      C.push_back(n);
    }
    // cout << C << endl;
    auto cost = lower_bound(C.begin(), C.end(), make_pair(N-1, 0ULL));
    if(cost==C.end()) {
      cout << "Case #" << (Z+1) << ": -1" << endl;
    } else {
      cout << "Case #" << (Z+1) << ": " << cost->second << endl;
    }
  }
}
