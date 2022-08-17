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
  int n, t;
  cin >> n >> t;
  vector<int> time(n);
  cin >> time[0];
  ll ans = 0;
  rep(i, 1, n)
  {
    cin >> time[i];
    int dist = time[i] - time[i - 1];
    if (dist < t)
    {
      ans += dist;
    }
    else
    {
      ans += t;
    }
  }
  ans += t;
  cout << ans << endl;
  return 0;
}
