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
  int x, y, z;
  cin >> x >> y >> z;
  int ans = 0;

  if (abs(x) < abs(y))
  {

    ans += abs(x);
  }
  else
  {
    if ((x > 0 && y < 0) || (x < 0 && y > 0))
    {
      ans += abs(x);
    }
    else
    {
      if (abs(y) < abs(z))
      {
        cout << -1 << endl;
        return 0;
      }
      ans += abs(z);
      ans += abs(x - z);
    }
  }
  cout << ans << endl;
  return 0;
}
