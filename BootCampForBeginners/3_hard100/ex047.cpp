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
  int k;
  cin >> k;
  ll ans = 0;
  queue<ll> q;
  rep(i, 1, 10)
  {
    q.push(i);
  }
  rep(i, 0, k)
  {
    ll x = q.front();
    ans = x;
    q.pop();
    ll tmp = 0;
    if (x % 10 != 0)
    {
      tmp = 10 * x + (x % 10) - 1;
      q.push(tmp);
    }
    tmp = 10 * x + (x % 10);
    q.push(tmp);
    if (x % 10 != 9)
    {
      tmp = 10 * x + (x % 10) + 1;
      q.push(tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
