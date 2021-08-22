#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <set>

using namespace std;

struct state {
  long Ad, Hd, Ak, Hk, move_number;
};

ostream& operator<<(ostream& os, const state& s) {
  os << "D[" << s.Ad << "|" << s.Hd << "] K[" << s.Ak << "|" << s.Hk << "]";
  return os;
}

// compare game states ignoring move number (for visited[])
bool cmp(const state& left, const state& right) {
  if(left.Ad < right.Ad) return true;
  if(left.Ad > right.Ad) return false;

  if(left.Hd < right.Hd) return true;
  if(left.Hd > right.Hd) return false;

  if(left.Ak < right.Ak) return true;
  if(left.Ak > right.Ak) return false;

  if(left.Hk < right.Hk) return true;
  if(left.Hk > right.Hk) return false;
  return false;
}

bool better(const state& left, const state& right) {
  if (left.Ad > right.Ad &&
      left.Hd >=right.Hd &&
      left.Ak <=right.Ak &&
      left.Hk <=right.Hk) return true;

  if (left.Ad >=right.Ad &&
      left.Hd > right.Hd &&
      left.Ak <=right.Ak &&
      left.Hk <=right.Hk) return true;

  if (left.Ad >=right.Ad &&
      left.Hd >=right.Hd &&
      left.Ak < right.Ak &&
      left.Hk <=right.Hk) return true;

  if (left.Ad >=right.Ad &&
      left.Hd >=right.Hd &&
      left.Ak <=right.Ak &&
      left.Hk < right.Hk) return true;
  return false;
}

int main(int argc, char* argv[]) {
  int CASES = 0;
  cin >> CASES;
  for(int CASE=1;CASE<=CASES;CASE++) {
    state initial;
    initial.move_number = 0;
    long B = 0, D = 0;

    cin >> initial.Hd >> initial.Ad >> initial.Hk >> initial.Ak >> B >> D;

    queue<state> Q;  // Queue for BFS
    Q.push(initial);
    state BEST = initial;  // BEST[i] := Best game state (for pruning)
    set<state,bool(*)(const state&, const state&)> visited(cmp);  // set of game states visited

    int victory_move = -1;
    while(Q.size() > 0) {
      state s(Q.front());
      // cout << s << endl;
      Q.pop();
      if(s.Hd == 0) continue;
      if(s.Hk == 0) {
        victory_move = s.move_number;
        break;
      }
      {
        state tmp(s);
        if(visited.find(tmp) != visited.end()) continue;
        visited.insert(tmp);
      }
      if(better(BEST, s)) continue;
      if(better(s, BEST)) BEST = s;

      // Attack
      state s_new(s); s_new.move_number++;
      s_new.Hk = max(s.Hk - s.Ad, 0L);
      if (s_new.Hk > 0) s_new.Hd = max(0L, s_new.Hd - s_new.Ak);
      // cout << " - " << s << " | " << s_new << endl;
      Q.push(s_new);

      // Buff
      s_new = s; s_new.move_number++;
      s_new.Ad += B;
      if (s_new.Hk > 0) s_new.Hd = max(0L, s_new.Hd - s_new.Ak);
      Q.push(s_new);

      // Cure
      s_new = s; s_new.move_number++;
      s_new.Hd = initial.Hd;
      if (s_new.Hk > 0) s_new.Hd = max(0L, s_new.Hd - s_new.Ak);
      Q.push(s_new);

      // Debuf
      s_new = s; s_new.move_number++;
      s_new.Ak = max(0L, s.Ak - D);
      if (s_new.Hk > 0) s_new.Hd = max(0L, s_new.Hd - s_new.Ak);
      Q.push(s_new);
    }
    if (victory_move == -1) {
      cout << "Case #" << CASE << ": IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << CASE << ": " << victory_move << endl;
    }
  }
}
