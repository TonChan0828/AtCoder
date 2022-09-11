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
  vector<vector<char>> t(4, vector<char>(4));
  rep(i, 0, 4)
  {
    rep(j, 0, 4)
    {
      cin >> t[i][j];
    }
  }

  rep(i, 0, 4)
  {
    rep(j, 0, 2)
    {
      char tmp = t[i][j];
      t[i][j] = t[i][3 - j];
      t[i][3 - j] = tmp;
    }
  }

  rep(i, 0, 2)
  {
    rep(j, 0, 4)
    {
      char tmp = t[i][j];
      t[i][j] = t[3 - i][j];
      t[3 - i][j] = tmp;
    }
  }

  rep(i, 0, 4)
  {
    rep(j, 0, 4)
    {
      if (j != 0)
      {
        cout << ' ';
      }
      cout << t[i][j];
    }
    cout << endl;
  }
  return 0;
}
