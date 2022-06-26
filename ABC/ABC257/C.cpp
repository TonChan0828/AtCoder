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
  string s;
  cin >> n >> s;
  vector<int> w(n);
  rep(i, 0, n)
  {
    cin >> w[i];
  }
  vector<pair<int, int>> p(n);
  rep(i, 0, n)
  {
    p[i] = make_pair(w[i], s[i]);
  }
  sort(p.begin(), p.end());
  int count0 = 0;
  int count1 = count(s.begin(), s.end(), '1');
  int weight = p[0].first;
  int ans = count1;
  rep(i, 0, n)
  {
    if (weight < p[i].first)
    {
      weight = p[i].first;
      ans = max(ans, count0 + count1);
    }
    if (p[i].second == '0')
    {
      count0++;
    }
    else if (p[i].second == '1')
    {
      count1--;
    }
  }
  ans = max(ans, count0);
  cout << ans << endl;
  return 0;
}
