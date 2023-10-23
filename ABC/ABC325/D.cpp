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
  cin >> n;
  vector<pair<ll, ll>> v(n);
  rep(i, 0, n) {
    ll t, d;
    cin >> t >> d;
    v[i] = {t, t + d};
  }
  sort(begin(v), end(v));
  priority_queue<ll, vector<ll>, greater<>> pq;
  int ans = 0;
  int it = 0;
  for (ll i = 0;; i++) {
    if (pq.empty()) {
      if (it == n) break;
      i = v[it].first;
    }
    while (it < n and v[it].first == i) {
      pq.push(v[it++].second);
    }
    while (!pq.empty() and pq.top() < i) pq.pop();
    if (!pq.empty()) {
      pq.pop();
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
