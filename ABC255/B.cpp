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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i, 0, k)
  {
    cin >> a[i];
  }
  vector<pair<int, int>> t(n);
  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    t[i] = make_pair(x, y);
  }

  double ans = 0;
  rep(i, 0, n)
  {
    double max = 1000000;
    rep(j, 0, k)
    {
      double tmp = sqrt(pow(double(abs(t[a[j] - 1].first - t[i].first)), 2) + pow(double(abs(t[a[j] - 1].second - t[i].second)), 2));
      chmin(max, tmp);
    }
    chmax(ans, max);
  }
  cout << setprecision(15);
  cout << ans << endl;
  return 0;
}
