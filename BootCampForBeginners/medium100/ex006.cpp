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
  vector<string> ans(h);
  rep(i, 0, h)
  {
    cin >> s[i];
  }
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (s[i][j] == '#')
      {
        ans[i].push_back('#');
      }
      else if (s[i][j] == '.')
      {
        int num = 0;
        rep(k, i - 1, i + 2)
        {
          rep(l, j - 1, j + 2)
          {
            if ((k >= 0 && l >= 0) && (k < h && l < w))
            {
              if (s[k][l] == '#')
              {
                num++;
              }
            }
          }
        }
        ans[i].push_back((char)('0' + num));
      }
    }
  }
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
