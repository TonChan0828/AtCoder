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
  const int v[] = {3, 5, 7};

  int ans = 0;

  rep(i, 3, 10)
  {
    int ma = 1;
    rep(j, 0, i)
    {
      ma *= 3;
    }

    rep(k, 0, ma)
    {
      int x = 0;
      int m = k;
      int cn[3] = {0, 0, 0};
      rep(l, 0, i)
      {
        int d = m % 3;
        x = x * 10 + v[d];
        cn[d]++;
        m /= 3;
      }
      if (x <= n && 0 < cn[0] && 0 < cn[1] && 0 < cn[2])
      {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
