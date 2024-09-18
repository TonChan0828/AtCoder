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
  vector<int> x(n + 1), p(n + 1);
  x[0] = -1001001001;
  rep(i, 1, n + 1) cin >> x[i];
  rep(i, 1, n + 1) cin >> p[i];

  map<int, int> mp;
  rep(i, 0, n + 1) mp[x[i]] = i;

  vector<ll> sum;
  sum.push_back(0);
  rep(i, 1, n + 1) sum.push_back(sum.back() + p[i]);

  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    auto itL = lower_bound(begin(x), end(x), l);
    auto itR = upper_bound(begin(x), end(x), r);
    if (itR == itL) {
      cout << "0\n";
    } else {
      --itL, --itR;
      cout << sum[mp[*itR]] - sum[mp[*itL]] << "\n";
    }
  }
  return 0;
}
