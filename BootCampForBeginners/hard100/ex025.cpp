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

int main()
{
  int n;
  cin >> n;
  vector<ll> c(n), s(n), f(n);
  rep(i, 0, n - 1)
  {
    cin >> c[i] >> s[i] >> f[i];
  }
  vector<ll> ans(n, 0);
  rep(i, 0, n - 1)
  {
    ans[i] = s[i];
    rep(j, 0, i + 1)
    {
      if (ans[j] < s[i])
      {
        ans[j] = s[i];
      }
      if (ans[j] % f[i] != 0)
      {
        ans[j] += f[i] - (ans[j] % f[i]);
      }
      ans[j] += c[i];
    }
  }

  rep(i, 0, n)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
