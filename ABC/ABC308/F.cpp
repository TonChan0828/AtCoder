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
    return a.first < b.first;
  }
  if (a.second != b.second) {
    return a.second > b.second;
  } else {
    return true;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  vector<ll> p(n), l(m), d(m);
  rep(i, 0, n) { cin >> p[i]; }
  sort(p.begin(), p.end());
  rep(i, 0, m) cin >> l[i];
  rep(i, 0, m) cin >> d[i];
  vector<pair<ll, ll>> ld(m);
  rep(i, 0, m) ld[i] = {l[i], d[i]};
  sort(ld.begin(), ld.end());
  priority_queue<pair<ll, ll>> pq;

  int pos = 0;
  rep(i, 0, n) {
    while (pos < m && ld[pos].first <= p[i]) {
      pq.push({ld[pos].second, ld[pos].first});
      ++pos;
    }
    if (pq.empty()) {
      sum += p[i];
    } else {
      sum += p[i] - pq.top().first;
      pq.pop();
    }
    // printf("%d %d %d\n", pos, sum, p[i]);
  }
  cout << sum << endl;
  return 0;
}
