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
  vector<string> s(n);
  ll count = 0;
  vector<ll> t(5);
  rep(i, 0, n)
  {
    cin >> s[i];
    if (s[i][0] == 'M')
    {
      t[0]++;
    }
    else if (s[i][0] == 'A')
    {
      t[1]++;
    }
    else if (s[i][0] == 'R')
    {
      t[2]++;
    }
    else if (s[i][0] == 'C')
    {
      t[3]++;
    }
    else if (s[i][0] == 'H')
    {
      t[4]++;
    }
  }
  rep(i, 0, t.size())
  {
    count += t[i];
  }
  ll ans = 0;

  rep(i, 0, 3)
  {
    rep(j, i + 1, 4)
    {
      rep(k, j + 1, 5)
      {
        ans += t[i] * t[j] * t[k];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
