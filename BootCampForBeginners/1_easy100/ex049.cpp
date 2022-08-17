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

int main()
{
  int h, w;
  cin >> h >> w;
  char p[h + 1][w + 1];
  rep(i, 0, h)
  {
    cin >> p[i];
  }
  rep(i, 0, w + 2) cout << "#";
  cout << endl;
  rep(i, 0, h)
  {
    cout << "#";
    rep(j, 0, w)
    {
      cout << p[i][j];
    }
    cout << "#" << endl;
  }
  rep(i, 0, w + 2) cout << "#";
  cout << endl;
  return 0;
}
