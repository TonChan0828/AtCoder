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

int cnt(ll n)
{
  int dig = 0;
  while (n > 0)
  {
    dig++;
    n /= 10;
  }
  return dig;
}

int main()
{
  ll n;
  cin >> n;

  int ans = cnt(n);
  for (ll a = 1; a * a <= n; a++)
  {
    if (n % a != 0)
    {
      continue;
    }
    ll b = n / a;
    int cur = max(cnt(a), cnt(b));
    chmin(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
