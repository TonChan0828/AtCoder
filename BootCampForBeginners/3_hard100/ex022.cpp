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
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  map<int, int> mps, mpt;
  int count = 1;
  rep(i, 1, s.size())
  {
    if (s[i] != s[i - 1])
    {
      mps[count]++;
      count = 1;
    }
    else
    {
      count++;
    }
  }
  mps[count]++;
  count = 1;
  rep(i, 1, t.size())
  {
    if (t[i] != t[i - 1])
    {
      mpt[count]++;
      count = 1;
    }
    else
    {
      count++;
    }
  }
  mpt[count]++;
  string ans = "Yes";
  for (const auto &[key, value] : mpt)
  {
    // cout << value << " " << mps[key] << endl;
    if (value != mps[key])
    {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  // cout << s << endl;
  // cout << t << endl;
  return 0;
}
