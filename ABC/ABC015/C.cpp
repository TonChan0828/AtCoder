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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> t(n, vector<int>(k));
  rep(i, 0, n) {
    rep(j, 0, k) { cin >> t[i][j]; }
  }

  auto dfs = [&](auto dfs, int turn, int res) -> bool {
    // cout << res << endl;
    if (turn == n) {
      return res == 0;
    }
    bool ans = false;
    for (int x : t[turn]) {
      ans |= dfs(dfs, turn + 1, res ^ x);
    }
    return ans;
  };

  if (dfs(dfs, 0, 0)) {
    cout << "Found" << endl;
  } else {
    cout << "Nothing" << endl;
  }
  return 0;
}
