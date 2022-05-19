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
  vector<pair<int, bool>> a(n + 1);
  rep(i, 1, n + 1)
  {
    int t;
    cin >> t;
    a[i] = make_pair(t, false);
  }
  int ans = 0;
  int pos = 1;
  rep(i, 0, n)
  {
    if (a[pos].first == 2)
    {
      ans++;
      break;
    }
    int nxt = a[pos].first;
    if (a[nxt].second)
    {
      ans = -1;
      break;
    }
    else
    {
      a[pos].second = true;
      ans++;
    }
    pos = nxt;
    // cout << pos << endl;
  }
  cout << ans << endl;
  return 0;
}
