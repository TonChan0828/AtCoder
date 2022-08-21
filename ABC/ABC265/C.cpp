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
  int h, w;
  cin >> h >> w;
  vector<vector<bool>> c(h, vector<bool>(w));
  vector<vector<char>> t(h, vector<char>(w));
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cin >> t[i][j];
    }
  }
  int x = 0, y = 0;
  while (1)
  {
    if (c[x][y])
    {
      cout << -1 << endl;
      return 0;
    }
    c[x][y] = true;
    bool cx = false, cy = false;
    if (t[x][y] == 'U')
    {
      x--;
      cx = true;
    }
    else if (t[x][y] == 'D')
    {
      x++;
    }
    else if (t[x][y] == 'L')
    {
      y--;
      cy = true;
    }
    else if (t[x][y] == 'R')
    {
      y++;
    }
    if ((x < 0 || x >= h))
    {
      if (cx)
      {
        x++;
      }
      else
      {
        x--;
      }
      cout << x + 1 << " " << y + 1 << endl;

      return 0;
    }

    if ((y < 0 || y >= w))
    {
      if (cy)
      {
        y++;
      }
      else
      {
        y--;
      }
      cout << x + 1 << " " << y + 1 << endl;

      return 0;
    }
    // cout << x << " " << y << endl;
  }
  return 0;
}
