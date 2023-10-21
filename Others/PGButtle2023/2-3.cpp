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
using mint = modint998244353;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  if (k == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<mint> kaizyo(n + 1);
  kaizyo[1] = 1;
  rep(i, 2, n) { kaizyo[i] = kaizyo[i - 1] * i; }

  vector<vector<int>> ma(k);
  rep(i, 0, n) { ma[i % k].push_back(a[i]); }

  vector<map<int, int>> vm(k);
  rep(i, 0, k) {
    for (int x : ma[i]) {
      vm[i][x]++;
    }
  }
  mint ans = 1;
  rep(i, 0, k) {
    int sz = ma[i].size();
    mint tmp = kaizyo[sz];
    for (auto [key, val] : vm[i]) {
      tmp /= kaizyo[val];
    }
    ans *= tmp;
  }
  cout << ans.val() << endl;
  return 0;
}
