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
  int n, k;
  cin >> n >> k;

  set<int> tops;
  vector<int> nxt(n, -1), num(n);
  vector<int> ans(n, -1);
  rep(i, 0, n)
  {
    int p;
    cin >> p;
    p--;
    auto it = tops.lower_bound(p);
    if (it == tops.end())
    {
      num[p] = 1;
      tops.insert(p);
    }
    else
    {
      int t = *it;
      tops.erase(it);
      nxt[p] = t;
      num[p] = num[t] + 1;
      tops.insert(p);
    }
    if (num[p] == k)
    {
      tops.erase(p);
      int t = p;
      while (t != -1)
      {
        ans[t] = i + 1;
        t = nxt[t];
      }
    }
  }
  rep(i, 0, n)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
