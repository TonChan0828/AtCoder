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
using mint = modint998244353;
// combination mod prime
// https://youtu.be/8uowVvQ_-Mo?t=6002
// https://youtu.be/Tgd_zLfRZOQ?t=9928
struct modinv {
  int n;
  vector<mint> d;
  modinv() : n(2), d({0, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(-d[mint::mod() % n] * (mint::mod() / n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
  int n;
  vector<mint> d;
  modfact() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back() * n), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} facts;
struct modfactinv {
  int n;
  vector<mint> d;
  modfactinv() : n(2), d({1, 1}) {}
  mint operator()(int i) {
    while (n <= i) d.push_back(d.back() * invs(n)), ++n;
    return d[i];
  }
  mint operator[](int i) const { return d[i]; }
} ifacts;
mint comb(int n, int k) {
  if (n < k || k < 0) return 0;
  return facts(n) * ifacts(k) * ifacts(n - k);
}

int main() {
  int n = 26;
  int k;
  cin >> k;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];

  vector<mint> dp(k + 1);
  dp[0] = 1;

  rep(i, 0, n) {
    vector<mint> old(k + 1);
    swap(old, dp);

    rep(j, 0, k + 1) {
      rep(a, 0, c[i] + 1) {
        int nj = a + j;
        if (nj > k) break;
        dp[nj] += old[j] * comb(nj, a);
      }
    }
  }

  mint ans;
  rep(i, 0, k) ans += dp[i + 1];
  cout << ans.val() << endl;
  return 0;
}
