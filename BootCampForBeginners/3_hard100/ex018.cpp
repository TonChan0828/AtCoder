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
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  rep(i, sx, tx)
  {
    cout << 'R';
  }
  rep(i, sy, ty)
  {
    cout << 'U';
  }
  rep(i, sx, tx)
  {
    cout << 'L';
  }
  rep(i, sy, ty)
  {
    cout << 'D';
  }
  cout << 'D';
  rep(i, sx, tx + 1)
  {
    cout << 'R';
  }
  rep(i, sy - 1, ty)
  {
    cout << 'U';
  }
  cout << 'L';
  cout << 'U';
  rep(i, sx - 1, tx)
  {
    cout << 'L';
  }
  rep(i, sy, ty + 1)
  {
    cout << 'D';
  }
  cout << 'R' << endl;
  return 0;
}
