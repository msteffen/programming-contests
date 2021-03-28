#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int N, M;

int ddr(int r, int c) {
  return (r-c)+(N-1);
}

int ddl(int r, int c) {
  return (r+c);
}

int points(char c) {
  switch(c) {
    case 'o':
      return 2;
    case 'x':
    case '+':
      return 1;
    default:
      return 0;
  }
}

void pg(vector<vector<char>> grid) {
  for (const auto& v : grid) {
    for (const auto c : v) {
      cout << c;
    }
    cout << endl;
  }
}

int main(int argc, char* argv[]) {
  int TESTCASES;
  cin >> TESTCASES;
  for(int CASE=1;CASE<=TESTCASES;CASE++) {
    cin >> N >> M;
    vector<vector<char>> grid(N, vector<char>(N, '.'));
    // Keep track of which rows, cols, and diags have been
    // tainted.
    vector<bool> badrow(N, false), badcol(N, false),
                 badddr(2*N-1, false), badddl(2*N-1, false);

    // Read in all M pre-placed models
    for(int i=0;i<M;i++) {
      char symbol;
      int row, col;
      cin >> symbol >> row >> col;
      row--; col--; // row, col are 1-based in the input
      grid[row][col] = symbol;
      if(symbol != '+') {
        badrow[row] = true;
        badcol[col] = true;
      } else if(symbol != 'x') {
        badddr[ddr(row,col)] = true;
        badddl[ddl(row,col)] = true;
      }
    }

    // Iterate through grid squares and try to improve
    // pg(grid);
    int score = 0;
    vector<string> ops;
    for(int i=0;i<N*N;i++) {
      stringstream op;
      int r=(i/N),c=(i%N);
      if (!badrow[r] &&
          !badcol[c] &&
          !badddr[ddr(r,c)] &&
          !badddl[ddl(r,c)]) {
        badrow[r] = true;
        badcol[c] = true;
        badddr[ddr(r,c)] = true;
        badddl[ddl(r,c)] = true;
        grid[r][c] = 'o';
        op << "o " << (r+1) << " " << (c+1);
      } else if (grid[r][c] == '.' &&
                 !badrow[r] && !badcol[c]) {
        badrow[r] = true;
        badcol[c] = true;
        grid[r][c] = 'x';
        op << "x " << (r+1) << " " << (c+1);
      } else if (grid[r][c] == '.' &&
                 !badddr[ddr(r,c)] && !badddl[ddl(r,c)]) {
        badddr[ddr(r,c)] = true;
        badddl[ddl(r,c)] = true;
        grid[r][c] = '+';
        op << "+ " << (r+1) << " " << (c+1);
      } else if (grid[r][c] == '+' &&
                 !badrow[r] && !badcol[c] &&
                 badddr[ddr(r,c)] && badddl[ddl(r,c)]) {
        // convert + to o and mess up row/col
        // (diags are already bad, and this is a +, so no
        // effect)
        badrow[r] = true;
        badcol[c] = true;
        grid[r][c] = 'o';
        op << "o " << (r+1) << " " << (c+1);
      } else if (grid[r][c] == 'x' &&
                 badrow[r] && badcol[c] &&
                 !badddr[ddr(r,c)] && !badddl[ddl(r,c)]) {
        // convert x to o and mess up row/col
        // (row/col are already bad, and this is a x, so no
        // effect)
        badddr[ddr(r,c)] = true;
        badddl[ddl(r,c)] = true;
        grid[r][c] = 'o';
        op << "o " << (r+1) << " " << (c+1);
      }
      score += points(grid[r][c]);
      if(op.peek()>0) {
        ops.push_back(op.str());
      }
      // pg(grid);
    }
    cout << "Case #" << CASE << ": " << score << " " << ops.size() << endl;
    for(const auto s : ops) cout << s << endl;
  }
}
