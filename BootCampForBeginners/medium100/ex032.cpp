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
  int n, y;
  cin >> n >> y;
  rep(i, 0, n + 1)
  {
    int remain = y - i * 10000;
    int gosen = remain / 5000;
    rep(j, 0, n - i + 1)
    {
      int remain5 = remain - 5000 * j;
      int k = n - i - j;
      if (remain5 == 1000 * k)
      {
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }
  }
  printf("-1 -1 -1\n");

  return 0;
}
