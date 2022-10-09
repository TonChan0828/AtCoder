#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n, m;
  const int dx[] = {1, 1, -1, -1};
  const int dy[] = {1, -1, 1, -1};
  vector<vector<int>> ans(400, vector<int>(400, -1));
  vector<pair<int, int>> hand;
  cin >> n >> m;

  rep(i, 0, n) {
    rep(j, i, n) {
      int t = i * i + j * j;
      if (t == m) {
        hand.push_back({i, j});
        hand.push_back({j, i});
      }
    }
  }
  ans[0][0] = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    pair<int, int> p = q.front();
    int x = p.first;
    int y = p.second;
    int count = ans[y][x];
    q.pop();
    rep(i, 0, hand.size()) {
      rep(j, 0, 4) {
        int nx = x + hand[i].first * dx[j];
        int ny = y + hand[i].second * dy[j];
        // cout << nx << " " << ny << endl;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (ans[ny][nx] != -1) continue;
        ans[ny][nx] = count + 1;
        q.push({nx, ny});
      }
    }
  }

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (j) {
        cout << " ";
      }
      cout << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}
