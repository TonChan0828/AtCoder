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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<vector<int>> t(n);

  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    t[x].push_back(y);
  }
  vector<pair<ll, int>> score(n, {10101010101, -1});

  rep(i, 0, n) {
    if (t[i].empty()) continue;
    if (score[i].first > a[i]) {
      score[i] = {a[i], i};
    }
    for (int x : t[i]) {
      if (score[x].first > score[i].first) {
        score[x] = score[i];
      }
    }
  }
  ll ans = LLONG_MIN;
  rep(i, 0, n) {
    if (i == score[i].second) continue;
    ans = max(ans, a[i] - score[i].first);
  }
  cout << ans << endl;
  return 0;
}
