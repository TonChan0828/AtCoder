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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i, 0, n)
  {
    cin >> w[i];
  }
  rep(i, 1, n)
  {
    // cout << w[i - 1] << endl;
    // cout << w[i][0] << endl;

    rep(j, 0, i - 1)
    {
      if (w[i] == w[j])
      {
        cout << "No" << endl;
        return 0;
      }
    }
    if (w[i - 1].at(w[i - 1].size() - 1) != w[i][0])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
