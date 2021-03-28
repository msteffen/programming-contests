#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  stringstream a, b;
  a << "t";
  cout << "a.good(): " << a.good() << endl;
  cout << "a.eof(): " << a.eof() << endl;
  cout << "a.peek(): " << a.peek() << endl;
  cout << "a.eof(): " << a.eof() << endl;
  cout << "b.good(): " << b.good() << endl;
  cout << "b.eof(): " << b.eof() << endl;
  cout << "b.peek(): " << b.peek() << endl;
  cout << "b.eof(): " << b.eof() << endl;
}
