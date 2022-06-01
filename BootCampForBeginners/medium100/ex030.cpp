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
  ll n, m;
  cin >> n >> m;
  ll ans;
  if (n == 1 && m == 1)
  {
    ans = 1;
  }
  else if (n == 1)
  {
    ans = m - 2;
  }
  else if (m == 1)
  {
    ans = n - 2;
  }
  else
  {
    ans = (n - 2) * (m - 2);
  }
  cout << ans << endl;
  return 0;
}
