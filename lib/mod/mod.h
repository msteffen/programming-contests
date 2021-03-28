#ifndef __MOD_H__
#define __MOD_H__

#include<iostream>
#include<functional>
#include<cstdlib>

using namespace std;

#ifndef BASE
#define BASE 1000000007LL
#endif
#define M(x) (((x)%BASE)<0 ? ((x)%BASE)+BASE : (x)%BASE)

typedef long long ll;

// This is the fastest implementation, so it goes first for easy copy/pasting
inline ll fmdiv(ll x, ll y) {
  ll y_inv;
  {
    ll r1(BASE), r2(y), b1(0), b2(1), b3;
    lldiv_t D;
    // Invariants:
    // a1*BASE + b1*y = r1
    // a2*BASE + b2*y = r2
    // BASE is prime, so r1 = gcd(BASE,y) = 1
    //   <=> a1*BASE + b1*y = 1
    //   <=> b1*y - 1 = -a1*BASE
    //   <=> b1*y = 1 (mod BASE)
    // Note: this function doesn't care about 'a' so we don't compute it.
    while(true) {
      if(r2 == 0LL) {
        y_inv = b1;
        break;
      }
      // r3 = r1%r2
      // r3 = r1 - r2*Q (where Q=r1/r2)
      // r3 = (a1*BASE + b1*y) - (a2*BASE + b2*y)*Q
      // r3 = (a1 - a2*Q)*BASE + (b1 - b2*Q)*y
      D = lldiv(r1, r2); // want regular, not modular division (see below)
      b3 = M(b1-M(b2*D.quot));
      r1 = r2;
      r2 = D.rem;
      b1 = b2;
      b2 = b3;
    }
  }
  return M(x*y_inv);
}

// mi stands for 'modulus integer' and can be used for modular arithmetic with
// the modulus BASE. If BASE is close to 9223372036854775807 this might
// encounter bugs, but in general I've tried to minimize overflow by taking the
// modulus frequently
struct mi {
 public:
  long long _i;
  mi(long long i) : _i(i%BASE >= 0 ? (i%BASE) : (i%BASE)+BASE) {}
};

inline mi operator+(mi x, mi y) {
  return mi(x._i+y._i);
}

inline mi operator-(mi x, mi y) {
  return mi(x._i-y._i);
}

inline mi operator*(mi x, mi y) {
  // TODO(msteffen) multiply by binary terms?
  return mi(x._i*y._i);
}

mi mi_inv(ll r1, ll r2, mi b1, mi b2) {
  // Invariants:
  // a1*BASE + b1*y = r1
  // a2*BASE + b2*y = r2
  // BASE is prime, so r1 = gcd(BASE,y) = 1
  //   <=> a1*BASE + b1*y = 1
  //   <=> b1*y - 1 = -a1*BASE
  //   <=> b1*y = 1 (mod BASE)
  // Note: this function doesn't care about 'a' so we don't compute it.
  if(r2 == 0LL) {
    return b1;
  }
  lldiv_t d = lldiv(r1, r2); // want regular, not modular division (see below)
  mi Q(d.quot);
  // r3 = r1%r2
  // r3 = r1 - r2*Q (where Q=r1/r2)
  // r3 = (a1*BASE + b1*y) - (a2*BASE + b2*y)*Q
  // r3 = (a1-a2*Q)*BASE + (b1-b2*Q)*y
  return mi_inv(r2, d.rem, b2, mi(b1)-(mi(b2)*Q));
};

inline mi operator/(mi x, ll y) {
  return x*mi_inv(BASE, y, 0, 1);
}

ll inv(ll r1, ll r2, ll b1, ll b2) {
  // Invariants:
  // a1*BASE + b1*y = r1
  // a2*BASE + b2*y = r2
  // BASE is prime, so r1 = gcd(BASE,y) = 1
  //   <=> a1*BASE + b1*y = 1
  //   <=> b1*y - 1 = -a1*BASE
  //   <=> b1*y = 1 (mod BASE)
  // Note: this function doesn't care about 'a' so we don't compute it.
  if(r2 == 0LL) {
    return b1;
  }
  lldiv_t d = lldiv(r1, r2); // want regular, not modular division (see below)
  // r3 = r1%r2
  // r3 = r1 - r2*Q (where Q=r1/r2)
  // r3 = (a1*BASE + b1*y) - (a2*BASE + b2*y)*Q
  // r3 = (a1 - a2*Q)*BASE + (b1 - b2*Q)*y
  return inv(r2, d.rem, b2, M(b1-M(b2*d.quot)));
};

inline ll mdiv(ll x, ll y) {
  ll y_inv = inv(BASE, y, 0, 1);
  return M(x*y_inv);
}


#endif
