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
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  ll ans = 0;
  if (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0)
  {
    ans = 0;
  }
  else
  {
    sort(a.begin(), a.end());
    ans = (ll)a[0] * a[1];
  }
  cout << setprecision(18);
  cout << ans << endl;
  return 0;
}
