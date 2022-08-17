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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater());

  ll ans = 0;
  ll e[2];
  vector<bool> f(n, false);
  int count = 0;
  rep(i, 0, n - 1)
  {
    if (a[i] == a[i + 1])
    {
      if (!f[i])
      {
        e[count] = a[i];
        f[i] = true;
        f[i + 1] = true;
        count++;
      }
    }
    if (count == 2)
    {
      ans = e[0] * e[1];
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
