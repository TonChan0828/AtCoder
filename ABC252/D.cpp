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

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> num;

  rep(i, 0, n)
  {
    cin >> a[i];
    num[a[i]]++;
  }
  vector<int> d(1);
  int count = 0;
  int sum = 0;
  for (const auto &[key, value] : num)
  {
    if (value > 1)
    {
      d.push_back(value);
      sum += value;
    }
    else if (value == 1)
    {
      count++;
    }
  }

  ll ans = count * (count - 1) * (count - 2);
  ans += count * sum;
  rep(i, 0, d.size() - 1)
  {
    rep(j, i + 1, d.size())
    {
      ans += d[i] * d[j] * count;
    }
  }
  rep(i, 0, d.size() - 2)
  {
    rep(j, i + 1, d.size() - 1)
    {
      rep(k, k + 1, d.size())
      {
        ans += d[i] * d[j] * d[k];
      }
    }
  }
  cout
      << ans << endl;
  return 0;
}
