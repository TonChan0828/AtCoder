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
  vector<ll> sum(n), sum2(n);
  vector<ll> p(n);
  rep(i, 0, n)
  {
    cin >> a[i];
    p[i] = a[i] * a[i];
    if (i != 0)
    {
      sum[i] = sum[i - 1] + a[i];
      sum2[i] = sum2[i - 1] + p[i];
    }
    else
    {
      sum[i] = a[i];
      sum2[i] = p[i];
    }
  }

  ll ans = 0;
  rep(i, 1, n)
  {
    ans += i * p[i] - (2 * sum[i - 1] * a[i]) + sum2[i - 1];
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
