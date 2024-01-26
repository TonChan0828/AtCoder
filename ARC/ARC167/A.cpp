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

using P = pair<ll, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(begin(a), end(a), greater());
  priority_queue<P, vector<P>, greater<P>> q;

  ll ans = 0;
  rep(i, 0, m) q.emplace(0, 0);
  int i = 0;
  while (i < n) {
    auto [tmp, cnt] = q.top();
    // cout << tmp << endl;
    q.pop();
    if (cnt == 2) {
      ans += tmp * tmp;
      continue;
    }
    q.emplace(tmp + a[i], cnt + 1);
    ++i;
  }
  while (!q.empty()) {
    auto [tmp, _] = q.top();
    q.pop();
    ans += tmp * tmp;
  }

  cout << ans << endl;
  return 0;
}
