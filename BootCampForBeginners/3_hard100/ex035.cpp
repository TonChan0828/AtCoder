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
  ll n, h;
  cin >> n >> h;
  vector<ll> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end(), greater());
  sort(b.begin(), b.end(), greater());
  ll count = 0;
  rep(i, 0, n)
  {
    if (b[i] < a[0] || h <= 0)
    {
      break;
    }
    h -= b[i];
    count++;
  }
  if (h > 0)
  {
    count += (h / a[0]);
    if (h % a[0] != 0)
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
