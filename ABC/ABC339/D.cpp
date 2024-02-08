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

using P = pair<int, int>;

const int INF = 1001001001;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<P> ps;

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (s[i][j] == 'P') ps.emplace_back(i, j);
    }
  }

  auto to_i = [&](vector<P> ps) {
    int res = 0;
    res = res * n + ps[0].first;
    res = res * n + ps[0].second;
    res = res * n + ps[1].first;
    res = res * n + ps[1].second;
    return res;
  };

  auto to_ps = [&](int id) {
    vector<P> ps(2);
    ps[1].second = id % n;
    id /= n;
    ps[1].first = id % n;
    id /= n;
    ps[0].second = id % n;
    id /= n;
    ps[0].first = id % n;
    id /= n;
    return ps;
  };

  int m = n * n * n * n;
  vector<int> dist(m, INF);
  queue<int> q;
  int sid = to_i(ps);
  dist[sid] = 0;
  q.push(sid);
  while (!q.empty()) {
    int id = q.front();
    q.pop();
    int d = dist[id];
    vector<P> ps = to_ps(id);
    rep(v, 0, 4) {
      vector<P> nps(2);
      rep(pi, 0, 2) {
        auto [i, j] = ps[pi];
        int ni = i + di[v], nj = j + dj[v];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n || s[ni][nj] == '#') {
          ni = i, nj = j;
        }
        nps[pi] = P(ni, nj);
      }
      int nid = to_i(nps);
      if (dist[nid] != INF) continue;
      dist[nid] = d + 1;
      q.push(nid);
    }
  }

  int ans = INF;
  rep(id, 0, m) {
    vector<P> ps = to_ps(id);
    int d = dist[id];
    if (ps[0] == ps[1]) ans = min(ans, d);
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}
