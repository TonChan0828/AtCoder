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
const int INF = INT32_MAX;

int main() {
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges;
  rep(i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    edges.emplace_back(u, v, w);
  }

  int ans = 0;
  rrep(i, 29, 0) {
    dsu uf(n);
    for (auto [a, b, c] : edges) {
      if (((c >> i | ans >> i)) != ans >> i) continue;
      uf.merge(a, b);
    }
    if (!uf.same(0, n - 1)) ans |= 1 << i;
  }

  cout << ans << endl;
  return 0;
}
