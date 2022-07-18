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
  cin >> n >> m;
  vector<bool> a(n, true);
  rep(i, 0, m)
  {
    int t;
    cin >> t;
    a[t] = false;
  }
  vector<ll> pos(n + 1);
  const ll mod = pow(10, 9) + 7;
  pos[0] = 1;
  if (a[1])
  {
    pos[1] = 1;
  }
  rep(i, 2, n + 1)
  {
    if (a[i])
    {
      pos[i] = (pos[i - 1] + pos[i - 2]) % mod;
    }
    else
    {
      pos[i] = 0;
    }
  }

  cout << pos[n] << endl;
  return 0;
}
