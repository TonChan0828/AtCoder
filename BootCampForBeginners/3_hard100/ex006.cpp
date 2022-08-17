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
  string sd, t;
  cin >> sd >> t;
  int size = sd.size();
  vector<string> ans;

  rep(i, 0, size - t.size() + 1)
  {
    bool ok = true;
    rep(j, 0, t.size())
    {
      if (sd[i + j] != t[j] && sd[i + j] != '?')
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      string s = sd;
      rep(j, 0, t.size())
      {
        s[i + j] = t[j];
      }
      rep(j, 0, size)
      {
        if (s[j] == '?')
        {
          s[j] = 'a';
        }
      }
      ans.push_back(s);
    }
  }
  if (!ans.empty())
  {
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
  }
  else
  {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}
