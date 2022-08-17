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

int main()
{
  ll n, min = LONG_LONG_MAX;
  cin >> n;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      min = i;
    }
  }
  min = (min - 1) + n / min - 1;

  cout << min << endl;
  return 0;
}
