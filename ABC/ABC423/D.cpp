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

using P = pair<ll, ll>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];

  priority_queue<P, vector<P>, greater<P>> q;
  ll now = 0;
  ll cnt = 0;
  vector<ll> ans(n);

  rep(i, 0, n) {
    while (cnt + c[i] > k) {
      auto [time, people] = q.top();
      q.pop();
      now = time;
      cnt -= people;
    }
    now = max(now, a[i]);
    ans[i] = now;
    cnt += c[i];
    q.push({now + b[i], c[i]});
  }

  for (ll x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
