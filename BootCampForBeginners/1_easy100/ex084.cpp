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
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n);
  ll sum = 0;
  rep(i, 0, n + 1)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    cin >> b[i];
    if (i == 0)
    {
      if (b[i] >= a[i])
      {
        sum += a[i];
        b[i] -= a[i];
      }
      else
      {
        sum += b[i];
        b[i] = 0;
      }
    }
    else
    {
      if ((b[i] + b[i - 1]) >= a[i])
      {
        sum += a[i];
        if (b[i - 1] <= a[i])
        {
          b[i] -= (a[i] - b[i - 1]);
        }
      }
      else
      {
        sum += (b[i] + b[i - 1]);
        b[i] = 0;
      }
    }
    // cout << b[i] << endl;
    // cout << sum << endl;
  }
  sum += min(a[n], b[n - 1]);

  cout << sum << endl;

  return 0;
}
