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
  int k, s;
  cin >> k >> s;
  ll ans = 0;
  rep(i, 0, k + 1)
  {
    rep(j, 0, k + 1)
    {
      int r = s - i - j;
      if (r <= k && r >= 0)
      {
        ans++;
        // cout << i << " " << j << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
