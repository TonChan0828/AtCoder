#include <bits/stdc++.h>
using namespace std;
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> d(m);
  rep(i, 1, n + 1) {
    int a;
    cin >> a;
    a += i;
    int l = (0 <= a) ? 0 : ((-a + i - 1) / i);
    int r = (n <= a) ? 0 : ((-(a - n) + i - 1) / i);
    r = min(r, m);
    rep(j, l, r) { d[j].push_back(a + i * j); }
  }

  rep(i, 0, m) {
    int sz = d[i].size();
    vector<bool> e(n + 1, false);
    rep(j, 0, sz) { e[d[i][j]] = true; }
    int ans = 0;
    while (e[ans]) {
      ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}
