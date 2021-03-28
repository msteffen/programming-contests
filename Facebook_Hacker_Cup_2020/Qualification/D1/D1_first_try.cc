
#include<bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
// FOR(x, A, B) binds the variable to integers in [A, B) and iterates over the
// interval in that order (A may be >B, but in this case x will take the values
// A, A-1, A-2, ..., B+1)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)&&i<CAT(__R_, __LINE__, __))||(CAT(__L_, __LINE__, __)>CAT(__R_, __LINE__, __)&&i>CAT(__R_, __LINE__, __));i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))

using namespace std;

// ostream& operator<<(ostream& o, vector<int> v) {
//   o<<"[";
//   FOR(i,0,v.size()) o<<(i==0?"":",") << v[i];
//   o<<"]";
//   return o;
// }

int N, M;
vector<int> C(1000000, 0); // Cost to fill at city i
// vector<int> D(1000000, 0); // Min cost to travel to i
// int MAX_INT(1ULL<<((8*sizeof(int))-2));
vector<unsigned long long> D(1000000, 0ULL); // Min cost to travel to i
unsigned long long MAX_ULL(1ULL<<((8*sizeof(unsigned long long))-1));

int main(int argc, char* argv[]) {
  // cout << sizeof(int) << " " << sizeof(unsigned long long) << " " << sizeof(-1+0ULL) << " " << (-1+0ULL) << endl;
  // cout << MAX_INT << endl;
  int ZZ;
  cin >> ZZ;
  FOR(Z,0,ZZ) {
    C.clear(); D.clear();
    cin >> N >> M;
    int c_next(0);
    FOR(i,0,N) {
      cin >> c_next;
      C.emplace_back(c_next);
      D.emplace_back(MAX_ULL);
    }
    C[0] = 0; // No sense in refilling in the first town
    D[0] = 0;
    // cout << C << endl << D << endl;
    FOR(l,0,N-1) {
      if(l>0 && C[l]==0) continue;
      FOR(r,min(l+M,N-1),l) D[r] = min(D[r], D[l]+C[l]);
    }

    if(D[N-1] == MAX_ULL) {
      cout << "Case #" << (Z+1) << ": -1" << endl;
    } else {
      cout << "Case #" << (Z+1) << ": " << D[N-1] << endl;
    }
  }
}
