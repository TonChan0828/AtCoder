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

// ll increase(int x, int y, int rLv, int bLv, ll rcount, ll bcount)
// {
//   if (bLv == 2)
//   {
//     return y;
//   };
//   ll count = 0;
// }
int main()
{
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> r(n + 1), b(n + 1);
  r[n] = 1;
  // b[n] = x;
  r[n - 1] = x + 1;
  int Lv = n;
  ll ans = 0;
  while (Lv > 1)
  {
    b[Lv] += r[Lv] * x;
    b[Lv - 1] = b[Lv] * y;
    r[Lv - 1] = b[Lv] + r[Lv];

    Lv--;
  }
  if (n == 1)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << b[1] << endl;
  }
  return 0;
}
