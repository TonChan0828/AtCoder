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
  vector<pair<int, int>> s(n);
  rep(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    s[i] = make_pair(b, a);
  }
  sort(s.begin(), s.end());
  string ans = "Yes";
  int time = 0;
  rep(i, 0, n)
  {
    time += s[i].second;
    if (time > s[i].first)
    {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
