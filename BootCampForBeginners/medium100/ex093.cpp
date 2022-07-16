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
  vector<vector<int>> s(m);
  rep(i, 0, m)
  {
    int k;
    cin >> k;
    rep(j, 0, k)
    {
      int t;
      cin >> t;
      s[i].push_back(t - 1);
    }
  }
  vector<int> p(m);
  rep(i, 0, m)
  {
    cin >> p[i];
  }

  int ans = 0;
  rep(i, 0, (1 << n))
  {
    vector<bool> sw(n);
    rep(j, 0, n)
    {
      if (i & (1 << j))
      {
        sw[j] = true;
      }
    }
    bool ok = true;
    rep(j, 0, m)
    {
      int count = 0;
      rep(k, 0, s[j].size())
      {
        int tar = s[j][k];
        if (sw[tar])
        {
          count++;
        }
      }
      if (count % 2 != p[j])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ans++;
      // cout << bitset<10>(i) << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
