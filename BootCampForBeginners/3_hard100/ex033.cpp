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
  vector<ll> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  vector<ll> ans(n);

  rep(i, 0, n)
  {
    if (i % 2 == 0)
    {
      ans[0] += a[i];
    }
    else
    {
      ans[0] -= a[i];
    }
  }
  rep(i, 1, n)
  {
    ans[i] = 2 * a[i - 1] - ans[i - 1];
  }
  rep(i, 0, n)
  {
    if (i)
    {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
