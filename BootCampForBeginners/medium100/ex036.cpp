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
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  a.push_back(x);
  sort(a.begin(), a.end());
  int max = a.back() - a[0];
  rep(i, 0, n - 1)
  {
    chmin(max, gcd(a[i + 1] - a[i], a[i + 2] - a[i + 1]));
  }
  cout << max << endl;

  return 0;
}
