#include<bits/stdc++.h>

#define FOR(i,l,r) \
  for (int i = (l); i < (r); ++i)


using namespace std;

const int Q = 10000;
const int S = 100;

int main() {
  int CASES, PROB;
  cin >> CASES;
  FOR(CASE,1,CASES+1) {
    cin >> PROB;
    vector<int> easyness(Q, 0);
    vector<vector<bool>> player(S);
    FOR(i,0,S) {
      player[i] = vector<bool>(Q)
      string line;
      cin >> line;
      FOR(j,0,Q) {
        if line[j] == '1' {
          player[i][j] = true;
          ++easiness[j];
        } else {
          player[i][j] = false;
        }
      }
    }
    vector<int> questions(Q);
    FOR(i,0,Q) questions[i] = i;
    sort(questions.begin(), questions.end(), [](int i, int j)->int {
        return easiness[i]<easiness[j];
    })

    int weirdest_p = 0;
    int weirdest_err = 0;
    FOR(p,0,P) {
      vector<int> errors(Q+1);
      FOR(q_i,0,Q) {
        cout << "q:" << q;
        if player[p][q_i]
      }

    }
    cout << "Case #" << CASE << ": " << weirdest_p;
  }
}


