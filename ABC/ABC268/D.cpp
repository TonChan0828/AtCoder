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
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  set<string> ts;
  rep(i, 0, n)
  {
    cin >> S[i];
  }

  rep(i, 0, m)
  {
    string t;
    cin >> t;
    ts.insert(t);
  }
  int max_u = 16 - (n - 1);
  rep(i, 0, n)
  {
    max_u -= S[i].size();
  }

  vector<bool> used(n, false);
  auto dfs = [&](auto f, int i, string s, int u) -> bool
  {
    if (i == n)
    {
      if (s.size() < 3)
      {
        return false;
      }
      if (ts.count(s))
      {
        return false;
      }
      cout << s << endl;
      return true;
    }

    if (u)
    {
      if (f(f, i, s + '_', u - 1))
      {
        return true;
      }
    }
    rep(j, 0, n)
    {
      if (!used[j])
      {
        used[j] = true;
        if (f(f, i + 1, s + '_' + S[j], u))
        {
          return true;
        }
        used[j] = false;
      }
    }
    return false;
  };

  rep(i, 0, n)
  {
    used[i] = true;
    if (dfs(dfs, 1, S[i], max_u))
    {
      return 0;
    }
    used[i] = false;
  }
  cout << -1 << endl;

  return 0;
}
