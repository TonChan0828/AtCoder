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
typedef pair<ll, int> pi;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  multiset<int> s, t;
  rep(i, 0, k) s.insert(0);
  rep(i, 0, n - k) t.insert(0);
  ll ans = 0;

  auto add = [&](int x) {
    s.insert(x);
    ans += x;
    int y = *s.begin();
    s.erase(s.find(y));
    ans -= y;
    t.insert(y);
  };

  auto del = [&](int x) {
    if (s.find(x) != s.end()) {
      s.erase(s.find(x));
      ans -= x;
      int y = *t.rbegin();
      t.erase(t.find(y));
      s.insert(y);
      ans += y;
    } else {
      t.erase(t.find(x));
    }
  };

  while (q--) {
    int x, y;
    cin >> x >> y;
    --x;
    add(y);
    del(a[x]);
    a[x] = y;
    cout << ans << "\n";
  }
  return 0;
}
