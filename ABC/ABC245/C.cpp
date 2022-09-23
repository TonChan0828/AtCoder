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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    cin >> b[i];
  }
  vector<bool> ab(n, false), bb(n, false);
  ab[0] = true;
  bb[0] = true;
  rep(i, 1, n)
  {
    if (ab[i - 1])
    {
      if (abs(a[i] - a[i - 1]) <= k)
      {
        ab[i] = true;
      }
      if (abs(b[i] - a[i - 1]) <= k)
      {
        bb[i] = true;
      }
    }
    if (bb[i - 1])
    {
      if (abs(a[i] - b[i - 1]) <= k)
      {
        ab[i] = true;
      }
      if (abs(b[i] - b[i - 1]) <= k)
      {
        bb[i] = true;
      }
    }
    if (!ab[i] && !bb[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
