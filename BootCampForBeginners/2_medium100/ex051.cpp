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
  vector<int> x(n), a(n);
  rep(i, 0, n)
  {
    cin >> x[i];
  }
  a = x;
  sort(a.begin(), a.end());
  int m = a[n / 2 - 1];
  rep(i, 0, n)
  {
    if (m >= x[i])
    {
      cout << a[n / 2] << endl;
    }
    else
    {
      cout << m << endl;
    }
  }
  return 0;
}
