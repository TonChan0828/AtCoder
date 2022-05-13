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
  int n, m;
  cin >> n;
  vector<string> s(n);
  map<string, int> count;
  rep(i, 0, n)
  {
    cin >> s[i];
    count[s[i]]++;
  }
  cin >> m;
  vector<string> t(m);
  rep(i, 0, m)
  {
    cin >> t[i];
    count[t[i]]--;
  }
  int max = 0;
  for (const auto &[key, value] : count)
  {
    chmax(max, value);
  }
  cout << max << endl;
  return 0;
}
