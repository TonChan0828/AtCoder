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
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, 0, n)
  {
    cin >> p[i];
  }
  map<int, int> m;
  rep(i, 0, n)
  {
    if (i == p[i])
    {
      m[0]++;
      m[1]++;
      m[n - 1]++;
    }
    else if (i > p[i])
    {
      int d = n - (i - p[i]);
      m[d]++;
      m[d + 1]++;
      m[d - 1]++;
    }
    else
    {
      int d = p[i] - i;
      m[d - 1]++;
      m[d]++;
      m[d + 1]++;
    }
  }
  int max = 0;
  for (const auto &[key, value] : m)
  {
    // cout << key << " " << value << endl;
    chmax(max, value);
  }
  cout << max << endl;
  return 0;
}
