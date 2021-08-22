#include <cstring>
#include <iostream>

using namespace std;

char* p(string& s) {
  return (char*) s.c_str();
}

int main(int argc, char* argv[]) {
  int TESTCASES;
  cin >> TESTCASES;
  for (int CASE=1; CASE <= TESTCASES; CASE++) {
    string line;
    cin >> line;
    string out = line;
    int dec = 0;

    // Special case -- only case where leading digit is 0
    if (line == "0") goto done;

    for(int i=0;(i+1)<line.length();i++) {
      if(line[i] <= line[i+1]) {
        // keep reading equal #s in case we get to the end,
        // but we decrement the first of a run
        if(line[i] < line[i+1]) dec = i+1;
        continue;
      }
      // line[i] cannot be 0, as the previous # would have triggered and the
      // first # is never 0
      line[dec] = (line[dec]-1);
      memset(p(line)+dec+1, '9', line.length()-dec-1);
      if(line[0] == '0') {
        for(int j=0;j<line.length();j++) {
          if(line[j] == '0') continue;
          out = string(line.length() - j, '.');
          memcpy(p(out),
                 p(line)+j,
                 line.length()-j);
          goto done;
        }
      } else {
        out = line;
      }
      goto done;
    }
done:
    cout << "Case #" << CASE << ": " << out << endl;
  }
}
