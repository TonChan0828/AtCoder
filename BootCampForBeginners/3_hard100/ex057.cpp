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
  vector<ll> a(n);
  vector<ll> sum(n);

  rep(i, 0, n)
  {
    cin >> a[i];
    if (i == 0)
    {
      sum[i] = a[i];
    }
    else
    {
      sum[i] = sum[i - 1] + a[i];
    }
  }
  ll cnt = 0;

  sum.push_back(0);
  map<ll, int> m;
  rep(i, 0, sum.size())
  {
    m[sum[i]]++;
  }
  for (const auto &[key, value] : m)
  {
    // cout << value << endl;
    if (value > 1)
    {
      ll tmp = 1;
      rep(i, 0, 2)
      {
        tmp *= value - i;
        tmp /= i + 1;
      }
      // cout << tmp << endl;
      cnt += tmp;
    }
  }
  cout << cnt << endl;
  return 0;
}
