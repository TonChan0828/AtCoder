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
  vector<int> a(n + 1);
  rep(i, 1, n + 1)
  {
    cin >> a[i];
  }
  vector<int> ans(n + 1);
  rrep(i, n, 1)
  {
    if (i + 2 > n)
    {
      ans[i] = a[i];
      continue;
    }

    int sum = 0;
    rep(j, 2, n / i + 1)
    {
      sum += ans[i * j];
    }
    if ((sum % 2 == a[i]))
    {
      ans[i] = 0;
    }
    else
    {
      ans[i] = 1;
    }
  }
  int count = 0;
  rep(i, 1, n + 1)
  {
    count += ans[i];
  }
  cout << count << endl;
  rep(i, 1, n + 1)
  {
    if (ans[i])
    {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
