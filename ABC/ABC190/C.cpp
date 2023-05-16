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
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m) cin >> a[i] >> b[i];
  int k;
  cin >> k;
  vector<vector<int>> cd(k, vector<int>(2));
  rep(i, 0, k) cin >> cd[i][0] >> cd[i][1];

  int ans = 0;
  rep(i, 0, 1 << k) {
    vector<int> t(n + 1, 0);
    int x = i;
    rep(j, 0, k) {
      ++t[cd[j][x % 2]];
      x = x >> 1;
    }
    int cnt = 0;
    rep(i, 0, m) {
      if (t[a[i]] && t[b[i]]) ++cnt;
    }

    ans = max(ans, cnt);
    // cout << i << " " << ans << endl;
    // rep(j, 0, n + 1) {
    //   if (j != 0) cout << " ";
    //   cout << t[j];
    // }
    // cout << endl;
  }

  cout << ans << endl;
  return 0;
}
