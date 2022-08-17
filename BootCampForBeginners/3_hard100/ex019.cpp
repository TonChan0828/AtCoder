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
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n + 1);
  rep(i, 1, n + 1)
  {
    cin >> a[i];
  }
  vector<vector<int>> c(h, vector<int>(w));
  int pos = 1;
  rep(i, 0, h)
  {
    if (i % 2 == 0)
    {
      rep(j, 0, w)
      {
        c[i][j] = pos;
        a[pos]--;
        if (a[pos] == 0)
        {
          pos++;
        }
      }
    }
    else
    {
      rrep(j, w - 1, 0)
      {
        c[i][j] = pos;
        a[pos]--;
        if (a[pos] == 0)
        {
          pos++;
        }
      }
    }
  }

  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
