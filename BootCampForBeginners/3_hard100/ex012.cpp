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
  vector<ll> d(n, 0);
  vector<int> cnt(n, 0);
  rep(i, 0, n)
  {
    cin >> d[i];
    cnt[d[i]]++;
  }

  ll r = 998244353;
  ll ans = 1;
  ll h = 1;

  if (d[0] == 0 && cnt[0] == 1)
  {
    h = cnt[0];
    rep(i, 1, n)
    {
      if (h == n)
      {
        break;
      }
      if (h < n && cnt[i] == 0)
      {
        ans = 0;
        break;
      }
      rep(j, 0, cnt[i])
      {
        ans *= cnt[i - 1];
        ans %= r;
      }
      h += cnt[i];
    }
  }
  else
  {
    ans = 0;
  }

  cout << ans << endl;
  return 0;
}
