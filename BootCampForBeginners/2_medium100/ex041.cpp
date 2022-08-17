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
  int ans = 100;
  rep(i, 0, s.length())
  {
    char tar = s[i];
    int pos = 0;
    int tmpMax = 0;

    rep(j, 0, s.length())
    {
      int dist = 0;
      if (j == 0)
      {
        if (tar == s[j])
        {
          dist = 0;
          pos = pos + 1;
        }
      }
      else if (j == s.length() - 1)
      {
        if (pos == 0)
        {
          dist = j - pos;
        }
        if (tar == s[j])
        {
          dist = j - pos - 1;
        }
        else
        {
          dist = j - pos;
        }
      }
      else
      {
        if (tar == s[j])
        {
          if (pos == 0)
          {
            dist = j - pos;
            pos = j;
          }
          else
          {
            dist = j - pos - 1;
            pos = j;
          }
        }
      }
      chmax(tmpMax, dist);
    }
    // cout << tmpMax << endl
    //      << endl;
    chmin(ans, tmpMax);
  }
  cout << ans << endl;
  return 0;
}
