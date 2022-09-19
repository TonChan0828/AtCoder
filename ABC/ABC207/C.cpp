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
  vector<pair<int, pair<double, double>>> s(n);
  rep(i, 0, n)
  {
    int t;
    double l, r;
    cin >> t >> l >> r;
    if (t == 2)
    {
      r -= 0.5;
    }
    if (t == 3)
    {
      l += 0.5;
    }
    if (t == 4)
    {
      l += 0.5;
      r -= 0.5;
    }
    s[i] = {t, {l, r}};
  }

  ll cnt = 0;
  rep(i, 0, n)
  {
    double li = s[i].second.first;
    double ri = s[i].second.second;
    rep(j, i + 1, n)
    {
      double lj = s[j].second.first;
      double rj = s[j].second.second;
      if (max(li, lj) <= min(ri, rj))
      {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
