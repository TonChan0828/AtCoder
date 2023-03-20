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
  ll l;
  int n1, n2;
  cin >> l >> n1 >> n2;
  vector<ll> v1(n1), l1(n1), v2(n2), l2(n2);
  rep(i, 0, n1) cin >> v1[i] >> l1[i];
  rep(i, 0, n2) cin >> v2[i] >> l2[i];

  ll ans = 0;
  int p1 = 0, p2 = 0;
  ll len1 = 0, len2 = 0;
  while (p1 < n1 || p2 < n2) {
    if (v1[p1] == v2[p2]) {
      ans += min(len1 + l1[p1], len2 + l2[p2]) - max(len1, len2);
    }

    if (len1 + l1[p1] <= len2 + l2[p2]) {
      len1 += l1[p1];
      ++p1;
    } else {
      len2 += l2[p2];
      ++p2;
    }
  }

  cout << ans << endl;
  return 0;
}
