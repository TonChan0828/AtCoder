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
  int n;
  cin >> n;
  vector g(n, vector<pair<int, ll>>());
  rep(i, 0, n - 1) {
    ll a, b;
    int x;
    cin >> a >> b >> x;
    --x;
    g[i + 1].emplace_back(i, a);
    g[x].emplace_back(i, b);
  }

  const ll INF = 1001001001001001;
  vector<ll> dp(n, INF);
  priority_queue<P, vector<P>, greater<P>> q;
  dp[n - 1] = 0;
  q.emplace(0, n - 1);
  while (!q.empty()) {
    auto [cost, pos] = q.top();
    q.pop();
    for (auto [x, val] : g[pos]) {
      if (chmin(dp[x], cost + val)) {
        q.emplace(dp[x], x);
      }
    }
  }

  cout << dp[0] << endl;
  return 0;
}
