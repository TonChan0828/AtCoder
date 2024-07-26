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
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int main() {
  int h, w, y;
  cin >> h >> w >> y;
  vector a(h, vector<int>(w, 0));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];

  vector drop(h, vector<bool>(w, false));
  priority_queue<pair<int, P>, vector<pair<int, P>>, greater<>> q;
  rep(i, 0, h) rep(j, 0, w) if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
      q.push({a[i][j], {i, j}});

  int ans = h * w;
  rep(i, 1, y + 1) {
    // cout << i << endl;
    while (!q.empty() && q.top().first <= i) {
      auto [ni, nj] = q.top().second;
      q.pop();
      if (drop[ni][nj]) continue;
      drop[ni][nj] = true;
      --ans;
      // cout << ni << " " << nj << endl;
      rep(d, 0, 4) {
        int di = ni + dy[d], dj = nj + dx[d];
        if (di < 0 || di >= h || dj < 0 || dj >= w) continue;
        if (drop[di][dj]) continue;
        q.push({a[di][dj], {di, dj}});
      }
    }
    // rep(k, 0, h) {
    //   rep(l, 0, w) {
    //     if (drop[k][l]) {
    //       cout << "x";
    //     } else {
    //       cout << "o";
    //     };
    //   }
    //   cout << endl;
    // }
    cout << ans << endl;
    // cout << endl;
  }

  return 0;
}
