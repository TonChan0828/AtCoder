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
  int n;
  cin >> n;
  vector<ll> ans(n + 1);
  ans[0] = 2;
  ans[1] = 1;
  rep(i, 2, n + 1)
  {
    ans[i] = ans[i - 1] + ans[i - 2];
    // cout << ans[i] << endl;
  }
  printf("%lld\n", ans[n]);
  return 0;
}
