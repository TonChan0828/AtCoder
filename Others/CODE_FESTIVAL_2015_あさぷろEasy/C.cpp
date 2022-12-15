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
  ll n, k;
  ll m, r;
  cin >> n >> k >> m >> r;
  vector<ll> s(n - 1);
  rep(i, 0, n - 1) cin >> s[i];
  sort(s.begin(), s.end(), greater());
  if (k < n) {
    ll sum = 0;
    rep(i, 0, k) sum += s[i];
    if (sum / k >= r) {
      cout << 0 << endl;
      return 0;
    }
  }

  ll nokori = r * k;
  rep(i, 0, k - 1) nokori -= s[i];
  if (nokori > m) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << max(nokori, 0LL) << endl;
  }

  return 0;
}
