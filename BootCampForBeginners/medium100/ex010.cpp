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
  ll ans = 0;
  // cout << num[1] << endl;
  for (const auto &[key, value] : num)
  {
    ll tmp = value;

    if (num.find(key - 1) != num.end())
    {
      tmp += num[key - 1];
    }
    if (num.find(key + 1) != num.end())
    {
      tmp += num[key + 1];
    }
    chmax(ans, tmp);
    // cout << num.size() << endl;
  }
  cout << ans << endl;
  return 0;
}
