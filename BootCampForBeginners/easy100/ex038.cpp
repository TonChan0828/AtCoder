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
  double a[5];
  int sum = 0;
  int max = 0;
  int c = 0;
  int tmp;
  rep(i, 0, 5)
  {
    cin >> a[i];
    int ce = ceil(a[i] / 10) * 10;
    tmp = ce - a[i];
    max = std::max(tmp, max);
    sum += ce;
  }
  sum -= max;
  cout << sum << endl;

  return 0;
}
