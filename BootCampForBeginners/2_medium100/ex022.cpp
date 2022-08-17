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
  double ans = 0;
  rep(i, 1, n + 1)
  {
    int count = 0;
    int sum = i;
    while (sum < k)
    {
      count++;
      sum *= 2;
    }
    // cout << count << endl;
    double ka = pow(2, count);
    // cout << ka << endl;
    ans += 1 / ka;
    // cout << ans << endl;
  }
  cout << setprecision(18);
  cout << ans / n << endl;
  return 0;
}
