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
const ll INF = 1001001001001;

int main() {
  int n;
  cin >> n;
  ll a, b, c;
  cin >> a >> b >> c;
  vector d(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> d[i][j];

  vector<ll> car(n, INF), bus(n, INF);
  vector<bool> vis(n, false);
  car[0] = 0;
  while (true) {
    int pos = -1;
    ll minDist = INF;
    rep(i, 0, n) {
      if (vis[i] || minDist <= car[i]) continue;
      pos = i;
      minDist = car[i];
    }
    if (pos == -1) break;
    vis[pos] = true;
    rep(i, 0, n) { car[i] = min(car[i], car[pos] + d[pos][i] * a); }
  }

  bus[n - 1] = 0;
  vector<bool> rvis(n, false);
  while (true) {
    int pos = -1;
    ll minDist = INF;
    rep(i, 0, n) {
      if (rvis[i] || minDist <= bus[i]) continue;
      pos = i;
      minDist = bus[i];
    }
    // cout << pos << endl;
    if (pos == -1) break;
    rvis[pos] = true;
    rep(i, 0, n) { bus[i] = min(bus[i], bus[pos] + d[pos][i] * b + c); }
  }

  // rep(i, 0, n) cout << car[i] << " ";
  // cout << endl;

  // rep(i, 0, n) cout << bus[i] << " ";
  // cout << endl;

  ll ans = car[n - 1];
  rep(i, 0, n) { ans = min(ans, car[i] + bus[i]); }
  cout << ans << endl;
  return 0;
}
