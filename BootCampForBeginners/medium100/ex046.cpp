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
  string s;
  cin >> s;
  map<char, int> map;
  rep(i, 0, s.length())
  {
    map[s[i]]++;
  }
  vector<int> a;
  int i = 0;
  for (const auto &[key, value] : map)
  {
    a.push_back(value);
    i++;
  }
  sort(a.begin(), a.end());
  string ans = "YES";
  if (a.size() == 2)
  {
    if (a.size() < s.length())
    {
      ans = "NO";
    }
  }
  else if (a.size() == 3)
  {
    if (a[1] - a[0] > 1 || a[2] - a[0] > 1)
    {
      ans = "NO";
    }
  }
  else if (a.size() == 1)
  {
    if (s.length() > 1)
    {
      ans = "NO";
    }
  }
  cout << ans << endl;
  return 0;
}
