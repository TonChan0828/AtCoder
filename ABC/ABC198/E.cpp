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
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];

  vector<vector<int>> g(n);
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> cnt(100001, 0);
  vector<bool> ans(n, false);

  auto dfs = [&](auto dfs, int x, int p = -1) -> void {
    // cout << x << endl;
    if (!cnt[c[x]]) ans[x] = true;
    cnt[c[x]]++;
    for (int y : g[x]) {
      if (y == p) continue;
      dfs(dfs, y, x);
    }
    cnt[c[x]]--;
  };

  dfs(dfs, 0);

  rep(i, 0, n) {
    if (ans[i]) printf("%d\n", i + 1);
  }
  return 0;
}
