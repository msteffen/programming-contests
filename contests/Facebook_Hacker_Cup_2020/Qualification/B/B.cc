#include<bits/stdc++.h>

#define CAT2(x, y, z) x ## y ## z
#define CAT(x, y, z) CAT2(x, y, z)
#define FOR(i,l,r) int CAT(__L_, __LINE__, __) = (l); int CAT(__R_, __LINE__, __) = (r); for(int i=CAT(__L_, __LINE__, __);i<CAT(__R_, __LINE__, __);i+=(CAT(__L_, __LINE__, __)<=CAT(__R_, __LINE__, __)?1:(-1)))

using namespace std;

int main(int argc, char* argv[]) {
  int ZZ;
  cin >> ZZ;
  FOR(Z,0,ZZ) {
    int TRASH;
    string stones;
    cin >> TRASH >> stones;
    int as(0), bs(0);
    FOR(i,0,stones.size()) stones[i] == 'A'?++as:++bs;
    // cout << TRASH << " . " << stones.size() << " A:" << as << " B:" << bs << endl;
    cout << "Case #" << (Z+1) << ": " << ((as-bs)*(as-bs)==1?"Y":"N") << endl;
  }
}
