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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int cnt = 0;
  rep(i, 0, h)
  {
    cin >> s[i];
    cnt += count(s[i].begin(), s[i].end(), '.');
  }

  const vector<int> dx = {1, 0, -1, 0};
  const vector<int> dy = {0, 1, 0, -1};

  vector<vector<int>> t(h, vector<int>(w, -1));
  queue<pair<int, int>> q;
  q.push({0, 0});
  t[0][0] = 1;
  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();

    rep(dir, 0, 4)
    {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= h || ny < 0 || ny >= w)
      {
        continue;
      }
      if (s[nx][ny] == '#')
      {
        continue;
      }

      if (t[nx][ny] == -1)
      {
        t[nx][ny] = t[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  int ans = -1;
  if (t[h - 1][w - 1] > 0)
  {
    ans = cnt - t[h - 1][w - 1];
  }
  cout << ans << endl;
  return 0;
}
