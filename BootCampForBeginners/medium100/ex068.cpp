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

bool check(int posH, int posW, int h, int w, vector<string> &a)
{
  bool cH, cW;
  if (posH <= h - 2)
  {
    if (a[posH + 1][posW] == '#')
    {
      cH = check(posH + 1, posW, h, w, a);
    }
    else
    {
      cH = false;
    }
  }
  if (posW <= w - 2)
  {
    if (a[posH][posW + 1] == '#')
    {
      cW = check(posH, posW + 1, h, w, a);
    }
    else
    {
      cW = false;
    }
  }
  if (posH == h - 1 && posW == w - 1)
  {
    return true;
  }
  // cout << cH << " " << cW << endl;
  if (cH || cW)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h)
  {
    cin >> a[i];
  }
  int count = 0;
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (a[i][j] == '#')
      {
        count++;
      }
    }
  }
  int posH = 0;
  int posW = 0;
  if (check(0, 0, h, w, a) && count == (h + w - 1))
  {
    cout << "Possible" << endl;
  }
  else
  {
    cout << "Impossible" << endl;
  }
  return 0;
}
