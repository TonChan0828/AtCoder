#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  int si, sj;
  cin >> si >> sj;
  int ti, tj;
  cin >> ti >> tj;
  --si, --sj, --ti, --tj;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  const int INF = 1e9;
  vector dist(h, vector<int>(w, INF));
  deque<pair<int, int>> q;
  dist[si][sj] = 0;
  q.emplace_back(si, sj);
  while (!q.empty()) {
    auto [i, j] = q.front();
    int d = dist[i][j];
    q.pop_front();
    if (dist[i][j] != d) continue;
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] <= d) continue;
      dist[ni][nj] = d;
      q.emplace_front(ni, nj);
    }
    rep(ei, -2, 3) {
      rep(ej, -2, 3) {
        int ni = i + ei, nj = j + ej;
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        if (dist[ni][nj] <= d + 1) continue;
        dist[ni][nj] = d + 1;
        q.emplace_back(ni, nj);
      }
    }
  }
  int ans = dist[ti][tj];
  cout << (ans == INF ? -1 : ans) << endl;

  return 0;
}
