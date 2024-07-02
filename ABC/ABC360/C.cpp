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
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), w(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> w[i];
  vector<P> p(n);
  vector<int> cnt(n, 0);
  rep(i, 0, n) {
    --a[i];
    cnt[a[i]]++;
    p[i] = {w[i], a[i]};
  }
  sort(begin(p), end(p));

  ll ans = 0;
  int now = 0;
  rep(i, 0, n) {
    // cout << now << endl;
    if (cnt[i]) continue;
    while (cnt[p[now].second] < 2) ++now;
    cnt[i]++;
    cnt[p[now].second]--;
    ans += p[now].first;
    ++now;
  }
  cout << ans << endl;
  return 0;
}
