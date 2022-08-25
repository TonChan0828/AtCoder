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
    ll tmp;
    cin >> tmp;
    a[tmp]++;
  }
  ll ans = 1;
  ll r = pow(10, 9) + 7;

  rep(i, 0, n)
  {
    if (i == 0)
    {
      if (a[i] > 1)
      {
        ans = 0;
        break;
      }
      continue;
    }
    if (a[i] == 0)
    {
      continue;
    }
    if (a[i] != 2)
    {
      ans = 0;
      break;
    }
    ans *= 2;
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}
