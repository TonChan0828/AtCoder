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
  vector<int> b(n, 1);
  vector<bool> r(n, false);
  r[0] = true;
  rep(i, 0, m)
  {
    int x, y;
    cin >> x >> y;
    b[x - 1]--;
    b[y - 1]++;
    if (r[x - 1])
    {
      r[y - 1] = true;
      if (b[x - 1] == 0)
      {
        r[x - 1] = false;
      }
    }
  }
  int ans = 0;
  rep(i, 0, n)
  {
    if (r[i])
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
