#include <iostream>
#include <vector>

typedef int i32;
typedef long i64; // long == long long
typedef float f32;
typedef double f64;
typedef long double f128;

// const i64 mod_base = 1000000007;
const i64 mod_base = 13;

using namespace std;

i64 inv_helper(i64 rpp, i64 rp, i64 spp, i64 sp) {
  if (rp == 0) {
    return spp;
  }
  i64 q = rpp/rp;
  i64 r = rpp%rp;

  // s = s_(n-1) - q*s_(n-1)
  i64 s = (q*sp) % mod_base;
  s = spp - s;
  while (s < 0) {
    s += mod_base;
  }
  return inv_helper(rp, r, sp, s);
}

i64 inv(i64 x) {
  return inv_helper(mod_base, x, 0, 1);
}

int main(int argc, char* argv[]) {
  i64 CASES = 0;
  cin >> CASES;
  for (int CASE=0;CASE<CASES;CASE++) {
    i64 N = 0l, M = 0l;
    cin >> N >> M;
    vector<i64> A(N-1, 0l), B(N-1, 0l), Y(M, 0l), H(M, 0l);
    for (i64 i=0;i<N-1;i++) {
      cin >> A[i] >> B[i];
    }
    for (i64 i=0;i<M;i++) {
      cin >> Y[i] >> H[i]
    }
    vector<i64> P_zl_n(M, 0l), P_zl_n(M, 0l), P_zr_n(M, 0l), P_zr_d(M, 0l);
    // for zombie_i...
    for (i64 i=0;i<M;i++) {
      // ...P(zombie_i makes it to the left)
      // j \in M, A[i] = lower height of fence to the right of yard_i
      for (i64 j=Y[i]-1;j>=0;j--) {
        P_zl_n[i] *= (H[i]-A[j]+1);
        P_zl_n[i] %= mod_base;
        P_zl_d[i] *= (B[j]-A[j]+1)
        P_zl_d[i] %= mod_base;
      }
      // ...P(zombie_i makes it to the right)
      for (i64 j=Y[i];j<(N-1);j++) {
        P_zr_n[i] *= (H[i]-A[j]+1);
        P_zr_n[i] %= mod_base;
        P_zr_d[i] *= (B[j]-A[j]+1)
        P_zr_d[i] %= mod_base;
      }
    }

  }
}
