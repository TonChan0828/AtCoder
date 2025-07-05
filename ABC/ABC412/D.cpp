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
  vector f(n, vector<bool>(n));
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) swap(u, v);
    f[u][v] = true;
  }

  int ans = 100;

  vector<int> a(n);
  rep(i, 0, n) a[i] = i;

  do {
    vector g(n, vector<bool>(n));
    rep(i, 0, n) {
      int u = a[i], v = a[(i + 1) % n];
      if (u > v) swap(u, v);
      g[u][v] = true;
    }

    int c0 = 0;
    rep(i, 0, n) rep(j, 0, n) {
      if (f[i][j] != g[i][j]) ++c0;
    }
    ans = min(ans, c0);

    rep(d, 3, n - 2) {
      vector h(n, vector<bool>(n));
      rep(i, 0, d) {
        int u = a[i], v = a[(i + 1) % d];
        if (u > v) swap(u, v);
        h[u][v] = true;
      }
      rep(i, 0, n - d) {
        int u = a[i + d], v = a[(i + 1) % (n - d) + d];
        if (u > v) swap(u, v);
        h[u][v] = true;
      }

      int c1 = 0;
      rep(i, 0, n) rep(j, 0, n) {
        if (f[i][j] != h[i][j]) ++c1;
      }
      ans = min(ans, c1);
    }
  } while (next_permutation(begin(a), end(a)));

  cout << ans << endl;
  return 0;
}
