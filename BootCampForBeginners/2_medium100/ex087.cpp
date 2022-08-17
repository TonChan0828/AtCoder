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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    cin >> b[i];
  }
  vector<int> c(n);
  ll ans = 0;
  ll plus = 0;
  ll minus = 0;
  rep(i, 0, n)
  {
    int diff = a[i] - b[i];
    c[i] = diff;
    if (diff < 0)
    {
      minus += diff;
      ans++;
    }
    else
    {
      plus += diff;
    }
  }
  sort(c.begin(), c.end(), greater());
  if (plus + minus < 0)
  {
    ans = -1;
  }
  else
  {
    rep(i, 0, n)
    {
      if (minus >= 0)
      {
        break;
      }
      minus += c[i];
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
