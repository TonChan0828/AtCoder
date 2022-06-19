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
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  map<int, int> ans;
  rep(i, 0, n)
  {
    cin >> a[i];
    if (a[i] <= w)
    {
      ans[a[i]]++;
    }
  }
  // for (const auto &[key, value] : ans)
  // {
  //   cout << key << endl;
  // }
  rep(i, 0, n - 1)
  {
    rep(j, i + 1, n)
    {
      int sum = a[i] + a[j];
      if (sum <= w)
      {
        ans[sum]++;
      }
    }
  }
  // for (const auto &[key, value] : ans)
  // {
  //   cout << key << endl;
  // }
  rep(i, 0, n - 2)
  {
    rep(j, i + 1, n - 1)
    {
      rep(k, j + 1, n)
      {
        int sum = a[i] + a[j] + a[k];
        if (sum <= w)
        {
          ans[sum]++;
        }
      }
    }
  }
  // for (const auto &[key, value] : ans)
  // {
  //   cout << key << endl;
  // }
  cout << ans.size() << endl;
  return 0;
}
