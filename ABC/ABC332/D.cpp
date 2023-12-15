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

const int INF = 1010101;

int main() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w)), b(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  rep(i, 0, h) rep(j, 0, w) cin >> b[i][j];

  int ans = INF;
  vector<int> row, column;
  rep(i, 0, h) row.push_back(i);
  rep(i, 0, w) column.push_back(i);
  do {
    do {
      int cnt = 0;
      rep(i, 0, h) {
        rep(j, 0, w) {
          if (a[row[i]][column[j]] != b[i][j]) continue;
          ++cnt;
        }
      }
      if (cnt != h * w) continue;

      int res = 0;
      auto tmp = row;
      rep(i, 0, h) {
        rep(j, 0, tmp.size()) {
          if (tmp[j] == i) {
            tmp.erase(tmp.begin() + j);
            res += j;
            break;
          }
        }
      }

      tmp = column;
      rep(i, 0, h) {
        rep(j, 0, tmp.size()) {
          if (tmp[j] == i) {
            tmp.erase(tmp.begin() + j);
            res += j;
            break;
          }
        }
      }
      chmin(ans, res);
    } while (next_permutation(begin(column), end(column)));
  } while (next_permutation(begin(row), end(row)));

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}
