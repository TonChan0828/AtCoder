#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

template <int MOD>
struct ModInt
{
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
  int get() const { return (int)x; }
  ModInt &operator+=(ModInt that)
  {
    if ((x += that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator-=(ModInt that)
  {
    if ((x += MOD - that.x) >= MOD)
      x -= MOD;
    return *this;
  }
  ModInt &operator*=(ModInt that)
  {
    x = (unsigned long long)x * that.x % MOD;
    return *this;
  }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  ModInt inverse() const
  {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b)
    {
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
  ModInt operator-() const
  {
    ModInt t;
    t.x = x == 0 ? 0 : Mod - x;
    return t;
  }
};
template <int MOD>
ostream &operator<<(ostream &st, const ModInt<MOD> a)
{
  st << a.get();
  return st;
};
template <int MOD>
ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k)
{
  ModInt<MOD> r = 1;
  while (k)
  {
    if (k & 1)
      r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
typedef ModInt<1000000007> mint;

int main()
{
  int X, Y;
  cin >> X >> Y;

  rep(a, 0, X + 1)
  {
    int b = X - a;
    if (b % 2 == 1)
    {
      continue;
    }
    b /= 2;
    if (2 * a + b == Y)
    {
      mint res = 1;
      rep(i, 0, a)
      {
        res *= (a + b) - i;
      }
      rep(i, 1, a + 1)
      {
        res /= i;
      }
      cout << res << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
