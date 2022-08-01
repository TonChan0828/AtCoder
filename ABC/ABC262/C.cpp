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
  vector<int> a(n + 1);
  ll same = 0;
  rep(i, 1, n + 1)
  {
    cin >> a[i];
    if (i == a[i])
    {
      same++;
    }
  }
  ll ans = (same * (same - 1)) / 2;
  ll count = 0;
  rep(i, 1, n + 1)
  {
    int t = a[i];
    if (a[t] == i && t != i)
    {
      count++;
    }
  }
  count /= 2;
  ans += count;
  cout << ans << endl;
  return 0;
}