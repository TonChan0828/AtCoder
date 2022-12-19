#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  map<int, int> l, r;

  rep(i, 0, n) {
    cin >> a[i];
    if (i < k) {
      l[a[i]] = i;
    } else {
      if (!r[a[i]]) r[a[i]] = i;
    }
  }
  int pre = 1e9;
  for (auto it = prev(r.end()); it != r.begin(); --it) {
    pre = min(pre, it->second);
    r[it->first] = (r[it->first], pre);
  }
  int ans = 1e9;
  rep(i, 0, k) {
    auto it = r.upper_bound(a[i]);
    if (it == r.end()) {
      continue;
    }
    ans = min(ans, (it->second - i));
  }
  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
