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

  vector<vector<int>> ans;
  auto dfs = [&](auto dfs, vector<int> &v) -> void {
    if (v.size() == n) {
      ans.push_back(v);
      return;
    }

    int x = v.back();
    if (x + 10 > m) return;
    int sz = v.size();
    rep(i, x + 10, m + 1 - ((n - sz - 1) * 10)) {
      v.push_back(i);
      dfs(dfs, v);
      v.pop_back();
    }
  };

  rep(i, 1, m + 1 - ((n - 1) * 10)) {
    vector<int> res;
    res.push_back(i);
    dfs(dfs, res);
  }

  cout << ans.size() << "\n";
  for (auto v : ans) {
    for (int x : v) cout << x << " ";
    cout << "\n";
  }

  return 0;
}
