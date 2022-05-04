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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int n, t, a;
  cin >> n >> t >> a;
  int h[n + 1], ans = 0;
  rep(i, 0, n)
  {
    cin >> h[i];
  }
  rep(i, 1, n)
  {
    if (abs(a - (t - (0.006 * h[ans]))) > abs(a - (t - (0.006 * h[i]))))
    {
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
