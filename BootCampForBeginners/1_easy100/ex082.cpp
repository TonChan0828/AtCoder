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
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  ll sum = 0;
  ll min = INT_MAX;
  int a = n / 2;
  int b = n % 2;
  chmin(min, 8 * q);
  chmin(min, 4 * h);
  chmin(min, 2 * s);
  chmin(min, d);
  // chmin(min, 4 * q + 2 * h);
  // chmin(min, 4 * q + s);
  // chmin(min, 2 * q + 3 * h);
  // chmin(min, 2 * q + h + s);
  // chmin(min, 2 * h + s);
  sum += (a * min);
  min = INT_MAX;
  chmin(min, 4 * q);
  chmin(min, 2 * h);
  chmin(min, 1 * s);
  // chmin(min, 2 * q + h);
  sum += (min * b);
  cout << setprecision(18);
  cout << sum << endl;
  return 0;
}
