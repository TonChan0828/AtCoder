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
  vector<int> a(n * 3);
  rep(i, 0, n * 3)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater());
  ll sum = 0;
  rep(i, 0, 2 * n)
  {
    if (i % 2 == 1)
    {
      sum += a[i];
    }
  }
  cout << setprecision(14);
  cout << sum << endl;
  return 0;
}
