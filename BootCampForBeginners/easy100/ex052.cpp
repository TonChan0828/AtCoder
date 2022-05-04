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
  int n;
  cin >> n;
  vector<int> a(n), b(n - 1);
  rep(i, 0, n - 1)
  {
    cin >> b[i];
  }
  a[0] = b[0];
  a[n - 1] = b[n - 2];
  rep(i, 1, n - 1)
  {
    a[i] = min(b[i], b[i - 1]);
  }
  int sum = 0;
  rep(i, 0, n)
  {
    // cout << a[i] << endl;
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}
