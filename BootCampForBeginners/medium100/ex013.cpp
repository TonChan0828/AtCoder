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
  vector<int> t(n + 1);
  vector<pair<int, int>> a(n + 1);
  a[0].first = 0;
  a[0].second = 0;
  rep(i, 1, n + 1)
  {
    cin >> t[i] >> a[i].first >> a[i].second;
  }
  string ans = "Yes";
  rep(i, 1, n + 1)
  {
    int dist = abs(a[i - 1].first - a[i].first) + abs(a[i - 1].second - a[i].second);
    int dt = t[i] - t[i - 1];
    if (dt < dist)
    {
      ans = "No";
      break;
    }
    else
    {
      if ((abs(dt - dist)) % 2 == 1)
      {
        ans = "No";
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
