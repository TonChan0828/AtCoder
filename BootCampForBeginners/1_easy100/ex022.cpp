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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  rep(i, 0, n - 1)
  {
    x -= a[i];
    if (x >= 0)
    {
      ans++;
    }
    else
    {
      break;
    }
  }
  if (a[n - 1] == x)
  {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
