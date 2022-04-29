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

int main()
{
  unsigned long n, a, b;
  cin >> n >> a >> b;
  unsigned long long ans = 0;
  ;
  if (a > 0)
  {
    ans = a * (n / (a + b));
    ans += min(n % (a + b), a);
  }
  cout << ans << endl;
  return 0;
}
