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
  int n, Q;
  cin >> n >> Q;

  using P = pair<int, int>;

  int ans = n;
  set<P> s;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    --l;

    auto it = s.lower_bound(P(l, -1));
    if (it != begin(s) && prev(it)->second >= l) it--;
    while (it != end(s) && it->first <= r) {
      ans += it->second - it->first;
      l = min(l, it->first);
      r = max(r, it->second);
      s.erase(it++);
    }

    s.emplace(l, r);
    ans -= r - l;

    cout << ans << "\n";
  }
  return 0;
}
