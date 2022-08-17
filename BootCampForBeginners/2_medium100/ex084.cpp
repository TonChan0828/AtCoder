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
  vector<int> l(n);
  rep(i, 0, n)
  {
    cin >> l[i];
  }
  sort(l.begin(), l.end());
  ll ans = 0;
  rep(i, 1, n - 1)
  {
    int b = l[i];
    rep(j, 0, i)
    {
      int a = l[j];
      rep(k, i + 1, n)
      {
        int c = l[k];
        if (c < a + b)
        {
          ans++;
        }
        else
        {
          break;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
