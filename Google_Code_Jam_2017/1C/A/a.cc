#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

typedef long long i;

typedef long double d;

struct p {
  int radius, height;

  p(int r, int h)
    : radius(r)
    , height(h)
    {}

  d side() {
    return 2 * M_PI * ((d)radius) * ((d)height);
  }

  d top() {
    return M_PI * ((d)radius) * ((d)radius);
  }

  ostream& operator<<(ostream& in) {
    in << "(" << radius << ", " << height << ")";
    return in;
  }
};

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    int N, K;
    cin >> N >> K;
    vector<p> ps;
    vector<int> side_sorted(N, 0), rad_sorted(N, 0);
    for (int i=0;i<N;i++) {
      p nextp(0, 0);
      cin >> nextp.radius >> nextp.height;
      ps.push_back(nextp);
      side_sorted[i] = i; rad_sorted[i] = i;
    }
    sort(side_sorted.begin(), side_sorted.end(),
        [&ps](int l, int r) -> bool { return ps[l].side() > ps[r].side(); });
    sort(rad_sorted.begin(), rad_sorted.end(),
        [&ps](int l, int r) -> bool { return ps[l].radius > ps[r].radius; });

    d side_area=0;
    int r_max = side_sorted[0];
    d best;
    for (int i=0;i<K;i++) {
      side_area += ps[side_sorted[i]].side();
      if(ps[side_sorted[i]].radius > ps[r_max].radius) r_max = side_sorted[i];
    }
    best = ps[r_max].top() + side_area;
    for (int i=0;i<N;i++) {
      if(rad_sorted[i] == r_max) break;
      d new_area =
        (side_area - ps[side_sorted[K-1]].side()) +
        ps[rad_sorted[i]].top() + ps[rad_sorted[i]].side();
      if(new_area > best) best = new_area;
    }

    cout.precision(numeric_limits<d>::max_digits10);
    cout << "Case #" << CASE << ": " << best << endl;
  }
}
