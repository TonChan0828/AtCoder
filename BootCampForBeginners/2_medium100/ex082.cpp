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
  sort(a.begin(), a.end());
  int ans = INT_MAX;
  rep(i, a[0], a[n - 1] + 1)
  {
    int sum = 0;
    int t = i;
    rep(j, 0, n)
    {
      sum += (a[j] - t) * (a[j] - t);
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
