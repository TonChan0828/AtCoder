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
  vector a(n, vector(n, vector<ll>(n)));
  vector sum(n, vector(n, vector<ll>(n)));
  rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) cin >> a[i][j][k];

  rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) {
    sum[i][j][k] = a[i][j][k];
    if (i > 0) sum[i][j][k] += sum[i - 1][j][k];
    if (j > 0) sum[i][j][k] += sum[i][j - 1][k];
    if (k > 0) sum[i][j][k] += sum[i][j][k - 1];
    if (i > 0 && j > 0) sum[i][j][k] -= sum[i - 1][j - 1][k];
    if (i > 0 && k > 0) sum[i][j][k] -= sum[i - 1][j][k - 1];
    if (j > 0 && k > 0) sum[i][j][k] -= sum[i][j - 1][k - 1];
    if (i > 0 && j > 0 && k > 0) sum[i][j][k] += sum[i - 1][j - 1][k - 1];
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    --lx, --rx, --ly, --ry, --lz, --rz;

    ll ans = sum[rx][ry][rz];
    if (lx > 0) ans -= sum[lx - 1][ry][rz];
    if (ly > 0) ans -= sum[rx][ly - 1][rz];
    if (lz > 0) ans -= sum[rx][ry][lz - 1];
    if (lx > 0 && ly > 0) ans += sum[lx - 1][ly - 1][rz];
    if (lx > 0 && lz > 0) ans += sum[lx - 1][ry][lz - 1];
    if (ly > 0 && lz > 0) ans += sum[rx][ly - 1][lz - 1];
    if (lx > 0 && ly > 0 && lz > 0) ans -= sum[lx - 1][ly - 1][lz - 1];

    cout << ans << endl;
  }
  return 0;
}
