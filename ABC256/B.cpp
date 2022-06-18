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
  vector<int> b(100);
  int ans = n - 3;
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, n - 3, n)
  {
    int tmp = a[i];
    rep(j, i + 1, n)
    {
      tmp += a[j];
    }
    if (tmp / 4 != 0)
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
