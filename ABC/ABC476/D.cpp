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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  ll x, y;
  cin >> x >> y;
  vector<ll> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  vector<ll> sumA(n + 1);
  rep(i, 0, n) sumA[i + 1] = sumA[i] + a[i];

  int ans = 0;
  rep(i, 0, m + 1) {
    ll v = x + k * y;
    int dif = upper_bound(begin(sumA), end(sumA), v) - begin(sumA) - 1;
    ans = max(ans, dif + i);
    if (i == m) break;
    ll need = (b[i] + k - 1) / k;
    if (need > y) break;
    x += need * k - b[i];
    y -= need;
  }
  cout << ans << endl;
  return 0;
}
