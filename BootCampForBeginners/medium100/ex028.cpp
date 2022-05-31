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
  int n, k;
  cin >> n >> k;
  int p[201010];
  double sum = 0;
  rep(i, 0, n)
  {
    cin >> p[i];
  }
  double e[201010];
  rep(i, 0, n)
  {
    e[i] = 1.0 * (1 + p[i]) / 2;
  }
  rep(i, 0, k)
  {
    sum += e[i];
  }
  double ans = sum;
  rep(i, k, n)
  {
    sum = sum + e[i] - e[i - k];
    chmax(ans, sum);
  }
  printf("%.10f\n", ans);

  return 0;
}
