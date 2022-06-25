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
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll min = std::min({a, b, c, d, e});

  ll tar = 0;
  if (n % min == 0)
  {
    tar = n / min;
  }
  else
  {
    tar = n / min + 1;
  }
  ll ans = tar + 4;
  cout << ans << endl;
  return 0;
}
