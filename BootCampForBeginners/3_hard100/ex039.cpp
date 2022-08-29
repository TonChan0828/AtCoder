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
  string s;
  cin >> s;

  int ans = 2002002;
  int cnt = 0;
  rep(i, 0, n)
  {
    if (s[i] == '.')
    {
      cnt++;
    }
  }
  ans = cnt;
  int b = 0, w = 0;
  rep(i, 0, n)
  {
    if (s[i] == '#')
    {
      b++;
    }
    else
    {
      w++;
    }
    ans = min(ans, b + cnt - w);
  }
  cout << ans << endl;
  return 0;
}
