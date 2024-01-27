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
  ll n, k;
  cin >> n >> k;
  k--;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> sum;
  vector<int> vis(n, -1);
  sum.push_back(a[0]);
  vis[0] = 0;
  int pos = 0, now = 0;

  rep(i, 0, n) {
    now++;
    pos = sum[i] % n;
    ll tmp = sum[i] + a[pos];
    sum.push_back(tmp);
    if (vis[pos] != -1) break;
    vis[pos] = i + 1;
  }

  // cout << now << endl;
  // for (ll x : sum) cout << " " << x;
  // cout << endl;

  ll ans = 0;
  if (k - now <= 0) {
    ans = sum[k];
  } else {
    int dist = now - vis[pos];
    ans = sum[now];
    k -= now;
    ans += (sum[now] - sum[vis[pos]]) * (k / dist);
    ans += sum[vis[pos] + k % dist] - sum[vis[pos]];
  }

  cout << ans << endl;
  return 0;
}
