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
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater());
  if (a[0] < k)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  rep(i, 0, n)
  {
    if (a[i] < k)
    {
      break;
    }
    if (a[i] == k)
    {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  int max = a[0];
  rep(i, 1, n)
  {
    max = gcd(max, a[i]);
  }
  int t = a[0];
  while (t > 0)
  {
    if (t == k)
    {
      cout << "POSSIBLE" << endl;
      return 0;
    }
    t -= max;
  }
  cout << "IMPOSSIBLE" << endl;

  return 0;
}
