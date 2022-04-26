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
  int x;
  cin >> x;
  int ans = 0;
  rep(i, x, 1000000)
  {
    bool check = false;
    rep(j, 2, x)
    {
      if ((i % j) == 0)
      {
        check = true;
        break;
      }
    }
    if (!check)
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
