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
const ll INF = 1001001001;
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> l(n, INF), r(n, INF);
  rep(i, 1, n) cin >> l[i];
  rep(i, 0, n - 1) cin >> r[i];

  vector<ll> mr(n, INF), ml(n, INF);
  mr[0] = r[0];
  rep(i, 1, n - 1) { mr[i] = min(mr[i - 1], r[i]); }
  ml[n - 1] = l[n - 1];
  rrep(i, n - 2, 1) { ml[i] = min(ml[i + 1], l[i]); }

  rep(qi, 0, q) {
    int s, t;
    cin >> s >> t;
    --s, --t;
    if (s < t) {
      cout << min(r[s], mr[s] + l[s]) << endl;
    } else {
      cout << min(l[s], ml[s] + r[s]) << endl;
    }
  }
  return 0;
}
