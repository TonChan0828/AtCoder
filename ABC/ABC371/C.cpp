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

int main() {
  int n, Mg, Mh;
  cin >> n;

  set<P> sm, sh;

  cin >> Mg;
  rep(i, 0, Mg) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    sm.insert({u, v});
  }

  cin >> Mh;
  rep(i, 0, Mh) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    sh.insert({a, b});
  }

  vector A(n, vector<int>(n));
  rep(i, 0, n - 1) rep(j, i + 1, n) cin >> A[i][j];

  vector<int> order(n);
  iota(begin(order), end(order), 0);

  int ans = 1001001001;

  do {
    // rep(i, 0, n) cout << " " << order[i];
    // cout << endl;
    vector<int> rOrder(n);
    rep(i, 0, n) rOrder[order[i]] = i;
    // rep(i, 0, n) cout << " " << rOrder[i];
    // cout << endl;
    int res = 0;
    for (auto [u, v] : sm) {
      int a = order[u], b = order[v];
      if (a > b) swap(a, b);
      if (sh.find({a, b}) == end(sh)) res += A[a][b];
    }
    for (auto [a, b] : sh) {
      int u = rOrder[a], v = rOrder[b];
      if (u > v) swap(u, v);
      if (sm.find({u, v}) == end(sm)) res += A[a][b];
    }
    // cout << res << endl;

    ans = min(ans, res);
  } while (next_permutation(begin(order), end(order)));

  cout << ans << endl;
  return 0;
}
