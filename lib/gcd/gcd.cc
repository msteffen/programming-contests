#include<iostream>
#include<functional>
#include<cstdlib>

using namespace std;

int egcd(int a, int b, int *p, int *q) {
  function<void(int,int,int,int,int,int)> f;
  f = [&f,a,b,p,q](int r1, int r2,
                  int p1, int q1,
                  int p2, int q2) {
    // Invariants:
    // p1*a + q1*b = r1
    // p2*a + q2*b = r2
    if(r2 == 0) {
      *p = p1; *q = q1;
      return;
    }
    int q = r1/r2;
    // r3 = r1%r2
    // r3 = r1 - r2*q
    // r3 = (p1*a + q1*b) - (p2*a+q2*b)*q
    f(r2, r1%r2, p2, q2, p1-(p2*q), q1-(q2*q));
  };
  f(a, b, 1, 0, 0, 1);
}

int main(int argc, char* argv[]) {
  if(argc<3) {
    cerr << "must pass \"a\" and \"b\" to find gcd coefficients" << endl;
    return 1;
  }
  int a, b, p, q;
  a = atoi(argv[1]);
  b = atoi(argv[2]);
  egcd(a, b, &p, &q);
}
