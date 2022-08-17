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
  int size = s.size();
  int ans = 0;
  if (size % 2 == 1)
  {
    int center = size / 2;
    char target = s[0];
    rep(i, 1, center + 1)
    {
      if (target != s[i])
      {
        target = s[i];
        ans++;
      }
    }
    target = s[size - 1];
    rrep(i, size - 1, center)
    {
      if (target != s[i])
      {
        target = s[i];
        ans++;
      }
    }
  }
  else
  {
    ans = INT_MAX;
    rep(i, 0, 2)
    {
      int center = size / 2 + i;
      char target = s[0];
      int count = 0;
      rep(i, 1, center + 1)
      {
        if (target != s[i])
        {
          target = s[i];
          count++;
        }
      }
      target = s[size - 1];
      rrep(i, size - 1, center)
      {
        if (target != s[i])
        {
          target = s[i];
          count++;
        }
      }
      chmin(ans, count);
    }
  }
  cout << ans << endl;
  return 0;
}
