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
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  int sum = 0;
  rep(i, 0, n)
  {
    sum += (((d - 1) / a[i]) + 1);
  }
  sum += x;
  cout << sum << endl;
  return 0;
}
