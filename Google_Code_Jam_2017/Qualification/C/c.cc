#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

bool bigger(ll l, ll r) {
  return l > r;
}

int main(int argc, char* argv[]) {
  int TESTCASES;
  cin >> TESTCASES;
  map<ll,ll,bool(*)(ll,ll)> sz_to_ct(bigger);
  for(int CASE=1;CASE<=TESTCASES;CASE++) {
    ll N, K;
    cin >> N >> K;
    sz_to_ct.clear();
    sz_to_ct[N] = 1;
    // minw = width of the smaller interval created by a
    //        person standing in the middle
    // maxw = width of the larger interval created
    //
    // Created outside the loop because we need to preserve
    // these for output.
    ll minw = 0, maxw = 0;
    while(K > 0) {
      auto e = *sz_to_ct.begin();
      ll width = e.first, cnt = e.second;
      if(cnt == 0) {
        sz_to_ct.erase(e.first);
        continue;
      }
      // cout << "{ " << e.first << ", " << e.second << " }" << endl;
      ll lose = min(cnt, K);
      K -= lose;
      sz_to_ct[width] = (cnt - lose);
      minw = ((width-1)/2); // floor((width-1)/2)
      maxw = (width/2); // ceil((width-1)/2)
      sz_to_ct[minw] += lose;
      sz_to_ct[maxw] += lose;
    }
    cout << "Case #" << CASE << ": " << maxw << " " << minw << endl;
  }
}
