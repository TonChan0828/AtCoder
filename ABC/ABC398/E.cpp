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
  vector<vector<int>> to(n);
  using P = pair<int, int>;
  vector<P> es;
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
    es.emplace_back(a, b);
  }

  vector<vector<int>> vs(2);
  auto dfs = [&](auto dfs, int v, int c, int p = -1) -> void {
    vs[c].push_back(v);
    for (int u : to[v]) {
      if (u == p) continue;
      dfs(dfs, u, c ^ 1, v);
    }
  };
  dfs(dfs, 0, 0);

  set<P> cand;
  for (int a : vs[0]) {
    for (int b : vs[1]) {
      cand.emplace(min(a, b), max(a, b));
    }
  }
  for (auto e : es) cand.erase(e);

  bool me = false;
  if (cand.size() % 2) me = true;
  if (me)
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  while (1) {
    if (me) {
      auto it = cand.begin();
      auto [a, b] = *it;
      cand.erase(it);
      ++a, ++b;
      cout << a << " " << b << endl;
    } else {
      int a, b;
      cin >> a >> b;
      if (a == -1) return 0;
      --a, --b;
      cand.erase(P(a, b));
    }
    me = !me;
  }
  return 0;
}
