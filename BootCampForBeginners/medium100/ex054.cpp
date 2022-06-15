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
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> t(n);
  rep(i, 0, n)
  {
    cin >> t[i];
  }
  sort(t.begin(), t.end());
  int ans = -1;
  int limit = -1;
  int count = 1;
  rep(i, 0, n)
  {
    if (limit < t[i])
    {
      ans++;
      limit = t[i] + k;
      count = 1;
    }
    else
    {
      count++;
      if (c < count)
      {
        ans++;
        limit = t[i] + k;
        count = 1;
      }
    }
    // cout << limit << " " << i << endl;
  }
  if (0 < count)
  {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
