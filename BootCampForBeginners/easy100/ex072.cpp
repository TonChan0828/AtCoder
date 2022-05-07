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
  int x;
  cin >> x;
  int min = 1000;
  rep(i, 1, x + 1)
  {
    int sum = 1;
    rep(j, 2, 11)
    {
      sum = pow(i, j);
      // cout << sum << endl;
      if (sum <= x)
      {
        min = std::min(min, x - sum);
      }
      else
      {
        break;
      }
    }
  }
  cout << x - min << endl;
  return 0;
}
