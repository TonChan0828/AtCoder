#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector s(k, vector<ll>(n + 1));
  rep(i, 0, n) s[i % k][i + 1] = a[i];
  rep(i, 0, k) {
    rep(j, 0, n) { s[i][j + 1] += s[i][j]; }
  }

  int q;
  cin >> q;
  rep(qi, 0, q) {
    int l, r;
    cin >> l >> r;
    --l;
    vector<ll> ns(k);
    rep(i, 0, k) ns[i] = s[i][r] - s[i][l];
    sort(ns.begin(), ns.end());
    if (ns[0] == ns.back())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
