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
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<int> info(n, 0);
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (s[i][j] == 'o') {
        info[i] |= (1 << j);
      }
    }
  }

  int ans = 1001001;
  rep(i, 1, (1 << n)) {
    int res = 0;
    int cnt = 0;
    rep(j, 0, n) {
      if (i & (1 << j)) {
        res |= info[j];
        ++cnt;
      }
    }
    bool comp = true;
    rep(j, 0, m) {
      if (!(res & (1 << j))) {
        comp = false;
        break;
      }
    }
    if (comp) ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
