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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector t(h, vector<char>(w, '.'));
  int y = 0, x = 0;
  int k = 0;
  rep(i, 0, n) {
    if (t[y % h][x % w] == '.') {
      t[y % h][x % w] = '#';
      k = (k + 1 + 4) % 4;
      y = (y + dy[k] + h) % h;
      x = (x + dx[k] + w) % w;
    } else {
      t[y % h][x % w] = '.';
      k = (k - 1 + 4) % 4;
      y = (y + dy[k] + h) % h;
      x = (x + dx[k] + w) % w;
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) { cout << t[i][j]; }
    cout << "\n";
  }

  return 0;
}
