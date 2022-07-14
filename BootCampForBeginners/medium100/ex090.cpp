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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> c(n);
  rep(i, 1, n)
  {
    if (s[i - 1] == 'A' && s[i] == 'C')
    {
      c[i] = c[i - 1] + 1;
    }
    else
    {
      c[i] = c[i - 1];
    }
  }
  rep(i, 0, q)
  {
    int l, r;
    cin >> l >> r;
    cout << c[r - 1] - c[l - 1] << endl;
  }
  return 0;
}
