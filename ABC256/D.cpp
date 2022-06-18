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
  vector<pair<int, int>> p(n);
  rep(i, 0, n)
  {
    int l, r;
    cin >> l >> r;
    p[i] = make_pair(l, r);
  }
  sort(p.begin(), p.end());
  // rep(i, 0, n)
  // {
  //   cout << p[i].first << " " << p[i].second << endl;
  // }
  int min = p[0].first;
  int max = p[0].second;
  rep(i, 0, n)
  {
    if (max < p[i].first)
    {
      cout << min << " " << max << endl;
      min = p[i].first;
      max = p[i].second;
    }
    else if (max < p[i].second)
    {
      max = p[i].second;
    }
  }

  cout << min << " " << max << endl;
  return 0;
}
