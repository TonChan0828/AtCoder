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
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  vector<vector<int>> b(n);
  int ans = n;

  rep(i, 0, n) {
    cin >> a[i];
    --a[i];
    ++c[a[i]];
  }

  rep(i, 0, n) {
    if (!c[i]) {
      --ans;
      b[0].push_back(i);
    }
  }

  rep(i, 0, n - 1) {
    int sz = b[i].size();
    if (sz == 0) break;
    rep(j, 0, sz) {
      c[a[b[i][j]]]--;
      if (c[a[b[i][j]]] == 0) {
        ans--;
        b[i + 1].push_back(a[b[i][j]]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
