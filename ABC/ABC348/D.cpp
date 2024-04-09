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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, int>;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  int n;
  cin >> n;
  map<P, int> mp;
  map<P, bool> used;
  rep(i, 0, n) {
    int r, c, e;
    cin >> r >> c >> e;
    --r, --c;
    mp[{r, c}] = e;
  }

  int si, sj, ti, tj;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (a[i][j] == 'S') si = i, sj = j;
      if (a[i][j] == 'T') ti = i, tj = j;
    }
  }

  vector energy(h, vector<int>(w, -1));
  priority_queue<pair<int, P>> q;
  energy[si][sj] = 0;
  q.push({0, {si, sj}});
  while (!q.empty()) {
    auto [cost, pos] = q.top();
    int i = pos.first, j = pos.second;
    // cout << i << " " << j << endl;
    q.pop();
    if (cost != energy[i][j]) continue;
    if (used[{i, j}] == false) {
      if (chmax(cost, mp[{i, j}])) {
        used[{i, j}] = true;
      }
    }
    energy[i][j] = cost;
    --cost;
    if (cost < 0) continue;
    rep(k, 0, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
      if (a[ni][nj] == '#') continue;
      if (cost <= energy[ni][nj]) continue;
      energy[ni][nj] = cost;
      q.push({cost, {ni, nj}});
    }
    // rep(i, 0, h) {
    //   rep(j, 0, w) { cout << energy[i][j] << " "; }
    //   cout << endl;
    // }
    // cout << endl;
  }

  // rep(i, 0, h) {
  //   rep(j, 0, w) { cout << energy[i][j] << " "; }
  //   cout << endl;
  // }

  if (energy[ti][tj] >= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
