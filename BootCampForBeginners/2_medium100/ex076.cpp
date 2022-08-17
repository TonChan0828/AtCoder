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
  string s;
  cin >> n >> s;
  int countE = count(s.begin(), s.end(), 'E');
  vector<int> e(n, countE), w(n, 0);
  rep(i, 0, n)
  {
    if (i < n - 1)
    {
      if (s[i] == 'W')
      {
        w[i + 1] = w[i] + 1;
      }
      else
      {
        w[i + 1] = w[i];
      }
    }

    if (i > 0)
    {
      if (s[i] == 'E')
      {
        e[i] = e[i - 1] - 1;
      }
      else
      {
        e[i] = e[i - 1];
      }
    }
    else
    {
      if (s[i] == 'E')
      {
        e[i]--;
      }
    }
  }
  int ans = INT_MAX;
  rep(i, 0, n)
  {
    ans = min(ans, e[i] + w[i]);
  }
  cout << ans << endl;
  return 0;
}
