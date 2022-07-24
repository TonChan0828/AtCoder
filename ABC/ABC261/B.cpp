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
  vector<vector<char>> a(n, vector<char>(n));
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      cin >> a[i][j];
    }
  }

  string ans = "correct";
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      if (i != j)
      {
        if (a[i][j] == 'W')
        {
          if (a[j][i] != 'L')
          {
            cout << "incorrect" << endl;
            return 0;
          }
        }
        if (a[i][j] == 'L')
        {
          if (a[j][i] != 'W')
          {
            cout << "incorrect" << endl;
            return 0;
          }
        }
        if (a[i][j] == 'D')
        {
          if (a[j][i] != 'D')
          {
            cout << "incorrect" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
