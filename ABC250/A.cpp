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
  int h, w, r, c;
  cin >> h >> w >> r >> c;
  int ans = 4;
  if (r == 1)
  {
    ans--;
  }
  if (r == h)
  {
    ans--;
  }
  if (c == 1)
  {
    ans--;
  }
  if (c == w)
  {
    ans--;
  }
  cout << ans << endl;
  return 0;
}
