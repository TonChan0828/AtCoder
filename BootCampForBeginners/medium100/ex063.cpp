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
  int w, h, n;
  cin >> w >> h >> n;
  int minX = 0, maxX = w;
  int minY = 0, maxY = h;
  rep(i, 0, n)
  {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1)
    {
      chmax(minX, x);
    }
    else if (a == 2)
    {
      chmin(maxX, x);
    }
    else if (a == 3)
    {
      chmax(minY, y);
    }
    else if (a == 4)
    {
      chmin(maxY, y);
    }
  }
  int ans = 0;
  if (minX >= maxX || minY >= maxY)
  {
    ans = 0;
  }
  else
  {
    ans = (maxX - minX) * (maxY - minY);
  }
  cout << ans << endl;
  return 0;
}
