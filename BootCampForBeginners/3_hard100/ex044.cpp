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
  int n;
  cin >> n;
  vector<int> honests[15];
  vector<int> liars[15];
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    rep(j, 0, a)
    {
      int x, y;
      cin >> x >> y;
      if (y == 0)
      {
        liars[i].push_back(x - 1);
      }
      else
      {
        honests[i].push_back(x - 1);
      }
    }
  }
  int ans = 0;
  rep(i, 0, 1 << n)
  {
    bool ok = true;
    int tot = 0;
    rep(j, 0, n)
    {
      if (i & (1 << j))
      {
        tot++;
        for (auto honest : honests[j])
        {
          if (!(i & (1 << honest)))
          {
            ok = false;
          }
        }
        for (auto liar : liars[j])
        {
          if ((i & (1 << liar)))
          {
            ok = false;
          }
        }
      }
    }
    if (ok)
    {
      chmax(ans, tot);
    }
  }
  cout << ans << endl;
  return 0;
}
