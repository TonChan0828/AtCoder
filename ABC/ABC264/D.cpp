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
  string t = "atcoder";
  string s;
  cin >> s;
  int count = 0;
  rep(i, 0, 7)
  {
    if (s[i] == t[i])
    {
      continue;
    }
    int pos = 0;
    rep(j, i, 7)
    {
      if (s[j] == t[i])
      {
        pos = j;
        break;
      }
    }
    count += pos - i;
    s.erase(s.begin() + pos);
    s.insert(s.begin() + i, t[i]);
    // cout << s << endl;
  }
  cout << count << endl;
  return 0;
}
