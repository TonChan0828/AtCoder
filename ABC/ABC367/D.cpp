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
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<ll> cnt(m, 0);
  vector<int> val(2 * n, 0);
  rep(i, 0, n - 1) {
    if (i) val[i] = val[i - 1];
    val[i] = (val[i] + a[i]) % m;
    cnt[val[i]]++;
    // cout << val[i] << " ";
  }

  ll ans = 0;
  int now = 0;
  rep(i, 0, n) {
    ans += cnt[now];
    cnt[val[i]]--;
    now = (now + a[i]) % m;
    int nxt = n - 1 + i;
    val[nxt] = (val[nxt - 1] + a[nxt % n]) % m;
    cnt[val[nxt]]++;
    // cout << val[nxt] << " ";
  }
  // cout << endl;

  cout << ans << endl;
  return 0;
}
