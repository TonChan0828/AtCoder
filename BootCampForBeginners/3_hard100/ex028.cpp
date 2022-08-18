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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, 0, n)
  {
    cin >> x[i];
  }
  int ans = INT_MAX;
  rep(i, 0, n - k + 1)
  {
    int tmp = x[i + k - 1] - x[i];
    tmp += min(abs(x[i]), abs(x[i + k - 1]));
    // cout << tmp << endl;
    ans = min(ans, tmp);
    // cout << ans << endl
    //  << endl;
  }
  if (n == 1)
  {
    ans = abs(x[0] - 0);
  }
  cout << ans << endl;
  return 0;
}
