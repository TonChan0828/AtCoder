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
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<pair<int, int>> a(n), b(n), c(n);
  rep(i, 0, n)
  {
    int t;
    cin >> t;
    a[i] = make_pair(t, i + 1);
  }
  rep(i, 0, n)
  {
    int t;
    cin >> t;
    b[i] = make_pair(t, i + 1);
  }
  rep(i, 0, n)
  {
    c[i] = make_pair(a[i].first + b[i].first, i + 1);
  }
  sort(a.begin(), a.end(), myCompare);
  sort(b.begin(), b.end(), myCompare);
  sort(c.begin(), c.end(), myCompare);

  vector<bool> g(n + 1);
  vector<int> ans;
  rep(i, 0, x)
  {
    ans.push_back(a[i].second);
    g[a[i].second] = true;
  }
  int count = 0;
  rep(i, 0, n)
  {
    if (count >= y)
    {
      break;
    }
    if (!g[b[i].second])
    {
      ans.push_back(b[i].second);
      g[b[i].second] = true;
      count++;
    }
  }
  count = 0;
  rep(i, 0, n)
  {
    if (count >= z)
    {
      break;
    }
    if (!g[c[i].second])
    {
      ans.push_back(c[i].second);
      count++;
    }
  }
  sort(ans.begin(), ans.end());

  rep(i, 0, ans.size())
  {
    cout << ans[i] << endl;
  }

  return 0;
}
