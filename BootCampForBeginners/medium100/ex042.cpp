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
  string s;
  cin >> s;
  vector<int> u(s.length()), d(s.length());
  u[0] = 1;
  d[0] = 0;
  rep(i, 1, s.length())
  {
    if (s[i] == 'U')
    {
      u[i] = u[i - 1] + 1;
    }
    else
    {
      u[i] = u[i - 1];
    }
    if (s[i] == 'D')
    {
      d[i] = d[i - 1] + 1;
    }
    else
    {
      d[i] = d[i - 1];
    }
  }
  ll ans = 0;
  rep(i, 0, s.length())
  {
    if (i != 0)
    {
      ans += u[i - 1] + 2 * d[i - 1];
    }
    if (i != s.length() - 1)
    {
      int du = u[u.size() - 1] - u[i];
      int dd = d[d.size() - 1] - d[i];
      ans += 2 * du + dd;
    }
  }
  cout << ans << endl;
  return 0;
}
