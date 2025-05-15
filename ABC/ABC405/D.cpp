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
const string sign = "v>^<";

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  int ei, ej;
  queue<pair<int, int>> q;
  rep(i, 0, h) {
    rep(j, 0, w) {
      if (s[i][j] == 'E') {
        ei = i, ej = j;
        q.push({ei, ej});
      }
    }
  }

  while (!q.empty()) {
    auto ij = q.front();
    q.pop();
    int i = ij.first, j = ij.second;

    rep(d, 0, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 || ni > h - 1 || nj < 0 || nj > w - 1) continue;
      if (!(s[ni][nj] == '.')) continue;
      // cout << ni << j << endl;
      s[ni][nj] = sign[d];
      q.push({ni, nj});
    }
  }

  rep(i, 0, h) cout << s[i] << "\n";
  return 0;
}
