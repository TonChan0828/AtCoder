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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int n, m, max = 0;
  cin >> n;
  int t[n];
  rep(i, 0, n)
  {
    cin >> t[i];
    max += t[i];
  }
  cin >> m;
  int p[m], x[m];
  rep(i, 0, m)
  {
    cin >> p[i] >> x[i];
  }
  rep(i, 0, m)
  {
    cout << max - t[p[i] - 1] + x[i] << endl;
  }
  return 0;
}
