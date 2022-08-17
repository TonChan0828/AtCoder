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
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  int odd = 0, even = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    if (a[i] % 2 == 0)
    {
      even++;
    }
    else
    {
      odd++;
    }
  }

  ll evenSum = pow(2, even);
  ll ans = 0;

  // rep(i, 0, odd + 1)
  // {
  //   int r = i;
  //   if (r % 2 == p)
  //   {
  //     ll mul = 1;
  //     ll h = 1;
  //     while (r > 0)
  //     {
  //       mul *= odd - r + 1;
  //       h *= r;
  //       r--;
  //     }
  //     ans += mul / h;
  //   }
  // }
  // ans *= evenSum;

  if (odd == 0)
  {
    if (p == 0)
    {
      ans += evenSum;
    }
  }
  else
  {
    ans += pow(2, n - 1);
  }

  cout << ans << endl;
  return 0;
}
