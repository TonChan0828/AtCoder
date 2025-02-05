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

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, m) cin >> t[i];

  rep(i, 0, n - m+1) {
    rep(j, 0, n - m+1) {
      bool ok = true;
      rep(k, 0, m) {
        rep(l, 0, m) {
          if (s[i + k][j + l] != t[k][l]) {
            ok = false;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        printf("%d %d\n", i + 1, j + 1);
        return 0;
      }
    }
  }
  return 0;
}
