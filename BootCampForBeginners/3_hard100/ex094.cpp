#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

template <int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  int get() const { return (int)x; }
  ModInt &operator+=(ModInt that) {
    if ((x += that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that) {
    if ((x += MOD - that.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that) {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt inverse() const {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      std::swap(a, b);
      u -= t * v;
      std::swap(u, v);
    }
    return ModInt(u);
  }
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const {
    ModInt t;
    t.x = x == 0 ? 0 : Mod - x;
    return t;
  }
};
template <int MOD>
ostream &operator<<(ostream &st, const ModInt<MOD> a) {
  st << a.get();
  return st;
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while (k) {
    if (k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
template <typename T, int FAC_MAX>
struct Comb {
  vector<T> fac, ifac;
  Comb() {
    fac.resize(FAC_MAX, 1);
    ifac.resize(FAC_MAX, 1);
    rep(i, 1, FAC_MAX) fac[i] = fac[i - 1] * i;
    ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
    rrep(i, FAC_MAX - 2, 1) ifac[i] = ifac[i + 1] * T(i + 1);
  }
  T aPb(int a, int b) {
    if (b < 0 || a < b) return T(0);
    return fac[a] * ifac[a - b];
  }
  T aCb(int a, int b) {
    if (b < 0 || a < b) return T(0);
    return fac[a] * ifac[a - b] * ifac[b];
  }
  T nHk(int n, int k) {
    if (n == 0 && k == 0) return T(1);
    if (n <= 0 || k < 0) return 0;
    return aCb(n + k - 1, k);
  }  // nHk = (n+k-1)Ck : n is separator
  T pairCombination(int n) {
    if (n % 2 == 1) return T(0);
    return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2));
  }
  // combination of paris for n
};
typedef ModInt<1000000007> mint;
Comb<mint, 4040> com;
int main() {
  int n, k;
  cin >> n >> k;
  int B = k;
  int R = n - k;
  ll r = pow(10, 9) + 7;
  rep(i, 1, k + 1) {
    int r = R - (i - 1);
    int b = B - i;
    mint ans = com.nHk(i, b) * com.nHk(i + 1, r);

    cout << ans << endl;
  }
  return 0;
}
