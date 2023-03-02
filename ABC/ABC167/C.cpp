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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, 0, n) {
    cin >> c[i];
    rep(j, 0, m) { cin >> a[i][j]; }
  }

  const int inf = 1300000;
  int ans = inf;
  rep(i, 1, (1 << n)) {
    int sum = 0;
    vector<int> score(m, 0);
    rep(j, 0, n) {
      if (i & (1 << j)) {
        sum += c[j];
        rep(k, 0, m) { score[k] += a[j][k]; }
      }
    }
    bool ok = true;
    rep(j, 0, m) {
      if (score[j] < x) {
        ok = false;
        break;
      }
    }
    if (ok) ans = min(ans, sum);
  }
  if (ans == inf) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
