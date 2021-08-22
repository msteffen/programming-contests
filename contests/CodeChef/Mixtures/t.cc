#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>

#define PEXPR(x) \
  cout << setw(30) << left << (#x + string(": ")) << "|" << setw(15) << right << (x) << endl

using namespace std;

const int SZ = 20;

ostream& operator<<(ostream& o, void *A) {
  o << "[";
  for (int i=0; i<SZ; i++) o << (i==0?"":", ") << ((int*)A)[i];
  o << "]";
  return o;
}

int main(int argc, char* argv[]) {
  PEXPR(sizeof(int));
  PEXPR((1<<(sizeof(int)*8)));
  PEXPR((1<<((sizeof(int)*8)-1)));
  PEXPR((1<<((sizeof(int)*8)-2)));

  cout << "------------------- SIZEOF -------------------------" << endl;
  int A[SZ];
  PEXPR(A);
  PEXPR(memset(A,0,4));
  PEXPR(memset(A,0,4*sizeof(int)));
  PEXPR(memset(A,0,20*sizeof(int)));
  PEXPR(memset(A,1,4));
  PEXPR(memset(A,1,4*sizeof(int)));
  PEXPR(memset(A,1,20*sizeof(int)));
}
