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

typedef pair<int, int> P;
const int INF = 11111111;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h)
  {
    cin >> s[i];
  }
  int ans = 0;
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (s[i][j] == '#')
      {
        continue;
      }
      vector<vector<int>> dist(h, vector<int>(w, INF));
      queue<P> q;
      auto update = [&](int ui, int uj, int x)
      {
        if (dist[ui][uj] != INF)
        {
          return;
        }
        dist[ui][uj] = x;
        q.push(P(ui, uj));
      };
      update(i, j, 0);
      while (!q.empty())
      {
        int qi = q.front().first;
        int qj = q.front().second;
        q.pop();
        rep(dir, 0, 4)
        {
          int ni = qi + di[dir];
          int nj = qj + dj[dir];
          if (ni < 0 || ni >= h || nj < 0 || nj >= w)
          {
            continue;
          }
          if (s[ni][nj] == '#')
          {
            continue;
          }
          update(ni, nj, dist[qi][qj] + 1);
        }
      }
      rep(ci, 0, h)
      {
        rep(cj, 0, w)
        {
          if (dist[ci][cj] == INF)
          {
            continue;
          }
          ans = max(ans, dist[ci][cj]);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
