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
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  vector<vector<int>> p(n, vector<int>(10 + 1));

  rep(i, 0, n) {
    rep(j, 0, 10) {
      int t;
      cin >> t;
      f[i][j] = t;
    }
  }
  rep(i, 0, n) {
    rep(j, 0, 11) {
      int t;
      cin >> t;
      p[i][j] = t;
    }
  }

  int ans = -1000000001;
  rep(i, 1, (1 << 10)) {
    vector<int> cnt(n, 0);
    rep(j, 0, 10) {
      if (!(i & (1 << j))) continue;
      rep(k, 0, n) {
        if (f[k][j]) ++cnt[k];
      }
    }
    int tmp = 0;
    rep(j, 0, n) { tmp += p[j][cnt[j]]; }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
