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
  // vector<vector<string>> t(n, vector<string>(m));
  int ac = 0, wa = 0;
  vector<int> ans(n), waCount(n);
  rep(i, 0, m)
  {
    int p;
    string s;
    cin >> p >> s;
    if (ans[p - 1] == 0)
    {
      if (s == "WA")
      {
        waCount[p - 1]++;
      }
      else if (s == "AC")
      {
        ac++;
        wa += waCount[p - 1];
        ans[p - 1] = 1;
      }
    }
    // t[p - 1].push_back(s);
  }
  cout << ac << " " << wa << endl;

  return 0;
}
