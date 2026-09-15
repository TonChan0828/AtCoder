#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, s;
  ll l;
  cin >> n >> s >> l;
  --s;
  vector<ll> a(n - 1);
  rep(i, 0, n - 1) cin >> a[i];

  vector<ll> sum(n);
  rep(i, 0, n - 1) sum[i + 1] = sum[i] + a[i];
  int ans = 0;
  rep(i, 0, s + 1) rep(j, s, n) {
    ll cost = min(2 * (sum[s] - sum[i]) + sum[j] - sum[s],
                  sum[s] - sum[i] + 2 * (sum[j] - sum[s]));
    // cout << sum[s] - sum[i] << " " << sum[j] - sum[s] << endl;

    if (cost > l) continue;
    ans = max(ans, j - i + 1);
  }
  cout << ans << endl;
  return 0;
}
