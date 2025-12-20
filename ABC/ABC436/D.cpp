#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, int>;
int di[] = {-1, 0, 0, 1};
int dj[] = {0, -1, 1, 0};
const int INF = 1001001;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  map<char, set<P>> mp;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] != '.' || s[i][j] != '#') mp[s[i][j]]
      .insert({i, j});

  vector dist(h, vector<int>(w, INF));

  queue<pair<P, int>> q;
  q.push({{0, 0}, 0});

  while (!q.empty()) {
    auto [p, d] = q.front();
    auto [i, j] = p;
    q.pop();
    if (d >= dist[i][j]) continue;
    dist[i][j] = d;
    // cout << i << " " << j << endl;
    if (s[i][j] != '.' && mp[s[i][j]].find({i, j}) != mp[s[i][j]].end()) {
      mp[s[i][j]].erase({i, j});
      stack<P> st;
      for (auto [ni, nj] : mp[s[i][j]]) {
        if (dist[ni][nj] != INF) continue;
        st.push({ni, nj});
        q.push({{ni, nj}, dist[i][j] + 1});
      }
      while (!st.empty()) {
        auto [ni, nj] = st.top();
        st.pop();
        mp[s[i][j]].erase({ni, nj});
      }
    }
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] != INF) continue;
      q.push({{ni, nj}, dist[i][j] + 1});
    }
  }

  // rep(i, 0, h) {
  //   rep(j, 0, w) printf("%8d ", dist[i][j]);
  //   cout << endl;
  // }

  if (dist[h - 1][w - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[h - 1][w - 1] << endl;
  }
  return 0;
}
