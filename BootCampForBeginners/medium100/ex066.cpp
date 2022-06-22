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
  vector<ll> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i] >> b[i];
  }
  ll count = 0;
  rrep(i, n - 1, 0)
  {
    a[i] += count;
    if (a[i] % b[i] != 0)
    {
      count += b[i] - (a[i] % b[i]);
    }
  }

  cout << count << endl;
  return 0;
}
