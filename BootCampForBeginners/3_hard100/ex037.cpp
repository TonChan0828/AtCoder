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
  int h, w, K;
  cin >> h >> w >> K;
  vector<vector<char>> s(h, vector<char>(w));
  vector<vector<int>> ans(h, vector<int>(w));
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cin >> s[i][j];
    }
  }
  int count = 1;
  int row = 0, column = 0;
  rep(i, 0, h)
  {
    // rep(k, 0, h)
    // {
    //   rep(j, 0, w)
    //   {
    //     cout << ans[k][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;

    int max = std::count(s[i].begin(), s[i].end(), '#');
    int c = 0;
    // cout << c << endl;
    if (max == 0)
    {
      continue;
    }
    if (max == 1)
    {
      rep(j, 0, w)
      {
        rep(k, row, i + 1)
        {
          ans[k][j] = count;
        }
      }
      count++;
      row = i + 1;
      continue;
    }
    rep(j, 0, w)
    {
      rep(k, row, i + 1)
      {
        ans[k][j] = count;
      }
      if (s[i][j] == '#')
      {
        c++;
        if (c < max)
        {
          count++;
        }
      }
    }
    count++;
    row = i + 1;
  }
  if (h != row)
  {
    int tr = 0;
    rep(i, 0, h)
    {
      if (ans[i][0] == 0)
      {
        tr = i;
        break;
      }
    }
    rep(j, 0, w)
    {
      rep(i, tr, h)
      {
        ans[i][j] = ans[tr - 1][j];
      }
    }
  }

  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
