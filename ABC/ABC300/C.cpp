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

int h, w;
vector<string> c(101);

const int dx[4] = {-1, 1, -1, 1};
const int dy[4] = {-1, -1, 1, 1};

int countX(int y, int x, int tar, int cnt) {
  // cout << " countX" << y << " " << x << endl;
  if (y < 0 || x < 0 || y >= h || x >= w) return cnt;
  if (c[y][x] == '.') return cnt;
  return countX(y + dy[tar], x + dx[tar], tar, cnt + 1);
}

int main() {
  cin >> h >> w;
  rep(i, 0, h) cin >> c[i];

  int n = min(h, w);
  vector<int> ans(n, 0);

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (c[i][j] == '.') continue;
      vector<int> box(4, 0);
      // cout << i << " " << j << endl;
      rep(k, 0, 4) {
        box[k] = countX(i, j, k, -1);
        // cout << box[k] << " ";
      }
      // cout << endl;
      bool ok = true;
      rep(k, 1, 4) {
        if (box[0] != box[k]) ok = false;
        break;
      }
      if (ok && box[0] > 0) ++ans[box[0] - 1];
    }
  }

  rep(i, 0, n) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
