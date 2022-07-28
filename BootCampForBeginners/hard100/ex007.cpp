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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);

  rep(i, 0, n)
  {
    cin >> a[i];
  }

  vector<pair<ll, int>> p(m);
  rep(i, 0, m)
  {
    int b, c;
    cin >> b >> c;
    p[i] = make_pair(c, b);
  }
  sort(a.begin(), a.end());
  sort(p.begin(), p.end(), greater());

  int pos = 0;
  int count = 0;

  rep(i, 0, n)
  {
    if (count == p[pos].second)
    {
      count = 0;
      pos++;
    }
    if (a[i] >= p[pos].first)
    {
      break;
    }
    a[i] = p[pos].first;
    count++;
  }

  ll ans = 0;
  rep(i, 0, n)
  {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
