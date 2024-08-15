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
const int M = 1e6;

vector<ll> f(vector<int> x) {
  int n = x.size();
  rep(i, 0, n) x[i] += M * 2;
  ll s = 0;
  rep(i, 0, n) s += x[i];
  vector<ll> res(M * 4 + 1);
  res[0] = s;

  int k = 0;
  sort(begin(x), end(x));
  rep(i, 1, M * 4 + 1) {
    while (k < n && x[k] < i) ++k;
    s -= n - k * 2;
    res[i] = s;
  }
  return res;
}

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];

  vector<ll> a = f(x);
  vector<ll> b = f(y);
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  ll ans = 0;
  int j = b.size() - 1;
  rep(i, 0, a.size()) {
    while (j >= 0 && a[i] + b[j] > d) --j;
    ans += j + 1;
  }
  cout << ans << endl;
  return 0;
}
