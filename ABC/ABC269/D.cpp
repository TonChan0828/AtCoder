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
  int n;
  cin >> n;
  set<pair<int, int>> s;
  map<pair<int, int>, bool> m;

  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
    m[{x, y}] = false;
  }
  const int dx[] = {-1, -1, 0, 0, 1, 1};
  const int dy[] = {-1, 0, -1, 1, 0, 1};

  int ans = 0;
  for (const auto &[key, value] : m)
  {
    auto kp = key;
    if (value)
    {
      continue;
    }
    ans++;
    queue<pair<int, int>> q;
    q.push(kp);
    m[kp] = true;
    while (!q.empty())
    {
      pair<int, int> p = q.front();
      q.pop();
      // cout << p.first << endl;
      rep(i, 0, 6)
      {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        if (s.count({nx, ny}))
        {
          if (!m[{nx, ny}])
          {
            q.push({nx, ny});
            m[{nx, ny}] = true;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
