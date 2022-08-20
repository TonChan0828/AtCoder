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
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> sum(n);
  sum[0] = a[0];
  rep(i, 1, n)
  {
    sum[i] = sum[i - 1] + a[i];
  }
  sort(sum.begin(), sum.end(), greater());
  sort(a.begin(), a.end(), greater());
  int ans = 1;
  rep(i, 1, n)
  {
    if (sum[i] * 2 >= a[i - 1])
    {
      ans++;
    }
    else
    {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
