#include <iostream>

using namespace std;

char flip(char c) {
  if (c == '-') return '+';
  return '-';
}

int main(int argc, char* argv[]) {
  int TESTCASES = 0;
  cin >> TESTCASES;
  for (int CASE=1; CASE <= TESTCASES; CASE++) {
    string line;
    int K = 0;
    cin >> line >> K;

    int flips = 0;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '-') {
        if ((i + K) > line.length()) {
          flips = -1;
          break;
        }
        for (int j = 0; j < K; j++) line[i+j] = flip(line[i+j]);
        flips++;
      }
    }
    if (flips < 0) {
      cout << "Case #" << CASE << ": IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << CASE << ": " << flips << endl;
    }
  }
}
