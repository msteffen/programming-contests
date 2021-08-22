#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <set>

using namespace std;

typedef long long lli;

int v(int town, int horse) {
  return (town*100)+horse;
}

int to_town(int v) {
  return v/100;
}

ostream& operator<<(ostream& os, const vector<vector<lli>>& v) {
  streamsize old(os.width());
  for(size_t i=0;i<v.size();i++) {
    for(size_t j=0;j<v[i].size();j++) {
      os.width(10);
      os.fill(' ');
      os << right;
      os << v[i][j];
    }
    os << endl;
  }
  os.width(old);
  return os;
}

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    int N, Q;
    cin >> N >> Q;

    vector<int> energy(N, 0), speed(N, 0);
    for(int i=0;i<N;i++) cin >> energy[i] >> speed[i];

    vector<vector<lli>> dist(N, vector<lli>(N, -1));
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        cin >> dist[i][j];
        // cout << "dist[" << i << "][" <<j << "]: " << dist[i][j] << endl;
      }
    }

    // Floyd-Warshall
    vector<vector<lli>> SP(dist);
    for(int k=0;k<N;k++) {
      // cout << SP << endl;
      for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
          if (SP[i][k] == -1 || SP[k][j] == -1) continue;
          if (SP[i][j] == -1 ||
              (SP[i][k] + SP[k][j] < SP[i][j])) SP[i][j] = (SP[i][k] + SP[k][j]);
        }
      }
    }

    // Product graph: vertices are (town, horse) (repr = town * 100 + horse)
    map<int,map<int, long double>> G;
    for(int town=0;town<N;town++) {
      for(int goal=0;goal<N;goal++) {
        G[v(town,goal)][v(town,town)] = 0; // able to switch horses

        if(SP[town][goal] == -1) continue;  // No path
        if(energy[town] < SP[town][goal]) continue;  // too far for horse

        int src = v(town,town), dest = v(goal,town);
        G[src][dest] = ((long double) SP[town][goal])/((long double) speed[town]);
      }
    }

    // Dijkstra's on product graph (too big for floyd-warshall)
    vector<long double> times;
    set<int> visited;
    for(int i=0;i<Q;i++) {
      int S, D;
      cin >> S >> D; S--; D--;
      long double final_dist = 0;

      priority_queue<pair<long double, int>> Q;
      Q.push(make_pair(S, 0));
      while(true) {
        pair<long double, int> next = Q.top();
        Q.pop();
        int v = next.second;
        long double d = next.first;

        if (visited.find(to_town(v)) != visited.end()) continue;
        visited.insert(to_town(v));

        if (to_town(v) == D) {
          final_dist = d;
          break;
        }
        for(const auto e : G[v]) {
          Q.push(make_pair(d + e.second, e.first));
        }
      }
      times.push_back(final_dist);
    }
    cout << "Case #" << CASE << ": ";
    for (const auto t : times) {
      cout.precision(2);
      cout << t;
    }
    cout << endl;
  }
}
