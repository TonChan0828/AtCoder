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

int h, w;

int root(int x, int y, vector<vector<char>> s)
{
  if (x == w - 1 && y == h - 1)
  {
    if (s[x][y] == '.')
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  int countx = INT_MAX, county = INT_MAX;
  if (s[y][x] == '.')
  {
    if (x + 1 < w)
    {
      countx = root(x + 1, y, s);
    }
    if (y + 1 < h)
    {
      county = root(x, y + 1, s);
    }
    return min(countx, county);
  }
  else
  {
    int cx = x;
    rep(i, x, h)
    {
      if (s[y][i] == '#')
      {
        cx = i;
        break;
      }
    }
    int cy = y;
    rep(i, y, h)
    {
      if (s[i][x] == '#')
      {
        cy = i;
        break;
      }
      rep(j, x, cx)
      {
        if (s[i][j] == '#')
        {
          cx = j;
          break;
        }
      }
    }
    rep(i, y, cy)
    {
      rep(j, x, cx)
      {
        s[i][j] = '.';
      }
    }

    if (x + 1 < w)
    {
      countx = root(x + 1, y, s);
    }
    if (y + 1 < h)
    {
      county = root(x, y + 1, s);
    }
    return min(countx, county) + 1;
  }
}

int main()
{
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cin >> s[i][j];
    }
  }
  vector<vector<int>> ans(h, vector<int>(w));
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      int countx = INT_MAX, county = INT_MAX;
      if (j > 0 && j < w)
      {
        if (s[i][j - 1] == '.' && s[i][j] == '#')
        {
          countx = 1 + ans[i][j - 1];
        }
        else
        {
          countx = ans[i][j - 1];
        }
      }
      if (i > 0 && i < h)
      {
        if (s[i - 1][j] == '.' && s[i][j] == '#')
        {
          county = 1 + ans[i - 1][j];
        }
        else
        {
          county = ans[i - 1][j];
        }
      }
      if (i == 0 && j == 0)
      {
        if (s[i][j] == '.')
        {
          ans[i][j] = 0;
        }
        else
        {
          ans[i][j] = 1;
        }
      }
      else
      {
        ans[i][j] = min(countx, county);
      }
      // cout << ans[i][j] << " ";
    }
    // cout << endl;
  }
  cout << ans[h - 1][w - 1] << endl;
  return 0;
}
