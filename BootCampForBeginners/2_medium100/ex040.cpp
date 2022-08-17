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
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i, 0, m)
  {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  ll ans = 0;
  if (n < m)
  {
    vector<pair<int, int>> dist;
    rep(i, 1, m)
    {
      dist.push_back(make_pair(abs(x[i] - x[i - 1]), i));
    }
    sort(dist.begin(), dist.end(), greater());
    dist.erase(dist.begin() + n - 1, dist.end());
    // rep(i, 0, dist.size())
    // {
    //   cout << dist[i].second << endl;
    // }
    vector<int> a;
    a.push_back(0);
    a.push_back(m);
    rep(i, 0, dist.size())
    {
      a.push_back(dist[i].second);
    }
    sort(a.begin(), a.end());
    rep(i, 1, a.size())
    {
      ans += x[a[i] - 1] - x[a[i - 1]];
    }
  }
  cout << ans << endl;
  return 0;
}
