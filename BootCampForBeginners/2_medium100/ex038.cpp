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
  int n, m;
  cin >> n;
  vector<int> d(n);
  rep(i, 0, n)
  {
    cin >> d[i];
  }
  cin >> m;
  vector<int> t(m);
  rep(i, 0, m)
  {
    cin >> t[i];
  }
  string ans = "YES";
  if (n < m)
  {
    ans = "NO";
  }
  else
  {
    sort(d.begin(), d.end());
    sort(t.begin(), t.end());
    int pos = 0;
    rep(i, 0, m)
    {
      bool flag = false;
      rep(j, 0, d.size())
      {
        if (d[j] == t[i])
        {
          d.erase(d.begin() + j);
          flag = true;
          break;
        }
      }
      // rep(j, 0, d.size())
      // {
      //   cout << d[j] << " ";
      // }
      // cout << endl;
      if (!flag)
      {
        ans = "NO";
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
