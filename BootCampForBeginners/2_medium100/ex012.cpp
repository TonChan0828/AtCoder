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
  vector<string> a(h);
  rep(i, 0, h)
  {
    cin >> a[i];
  }
  rep(i, 0, a.size())
  {
    int count = 0;
    rep(j, 0, a[i].size())
    {
      if (a[i][j] == '#')
      {
        break;
      }
      else
      {
        count++;
      }
    }
    if (count == a[i].size())
    {
      a.erase(a.begin() + i);
      i--;
    }
  }
  rep(i, 0, a[0].size())
  {
    int count = 0;
    rep(j, 0, a.size())
    {
      if (a[j][i] == '#')
      {
        break;
      }
      else
      {
        count++;
      }
    }
    if (count == a.size())
    {
      rep(j, 0, a.size())
      {
        a[j].erase(a[j].begin() + i);
      }
      i--;
    }
  }
  rep(i, 0, a.size())
  {
    cout << a[i] << endl;
  }
  return 0;
}
