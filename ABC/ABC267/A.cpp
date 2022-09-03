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
  cin >> s;
  int ans = 0;
  if (s == "Monday")
  {
    ans = 5;
  }
  else if (s == "Tuesday")
  {
    ans = 4;
  }
  else if (s == "Wednesday")
  {
    ans = 3;
  }
  else if (s == "Thursday")
  {
    ans = 2;
  }
  else if (s == "Friday")
  {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}
