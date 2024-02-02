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

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i, 0, m) {
    cin >> x[i];
    --x[i];
  }
  vector<ll> cnt(n + 1, 0);
  rep(i, 0, m - 1) {
    int s = min(x[i], x[i + 1]);
    int t = max(x[i], x[i + 1]);
    int a = t - s, b = n - a;
    cnt[0] += a;
    cnt[s] -= a;
    cnt[s] += b;
    cnt[t] -= b;
    cnt[t] += a;
    cnt[n] -= a;
  }

  rep(i, 0, n) cnt[i + 1] += cnt[i];
  // rep(i, 0, n + 1) cout << cnt[i] << " ";
  // cout << endl;
  ll ans = *min_element(cnt.begin(), cnt.begin() + n);
  cout << ans << endl;
  return 0;
}
