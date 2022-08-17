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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h)
  {
    cin >> s[i];
  }
  string ans = "Yes";
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (s[i][j] == '#')
      {
        int count = 0;
        if (i - 1 >= 0)
        {
          if (s[i - 1][j] == '#')
          {
            count++;
          }
        }
        if (i + 1 < h)
        {
          if (s[i + 1][j] == '#')
          {
            count++;
          }
        }
        if (j - 1 >= 0)
        {
          if (s[i][j - 1] == '#')
          {
            count++;
          }
        }
        if (j + 1 < w)
        {
          if (s[i][j + 1] == '#')
          {
            count++;
          }
        }
        if (count == 0)
        {
          ans = "No";
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
