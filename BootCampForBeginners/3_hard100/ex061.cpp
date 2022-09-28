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
  string s;
  int k;
  cin >> s >> k;
  rep(i, 0, s.size())
  {
    if (s[i] == 'a')
    {
      continue;
    }
    int dist = s[i] - 'a';
    if (k >= 26 - dist)
    {
      s[i] = s[i] - dist;
      k -= 26 - dist;
    }
  }
  s[s.size() - 1] = s[s.size() - 1] + (k % 26);
  cout << s << endl;
  return 0;
}
