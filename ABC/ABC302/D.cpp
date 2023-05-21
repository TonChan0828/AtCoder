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

int main() {
  int n, m;
  ll d;
  cin >> n >> m >> d;

  vector<ll> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = -1;
  rep(i, 0, n) {
    auto itr = lower_bound(b.begin(), b.end(), a[i] + d + 1);
    --itr;
    if (llabs(a[i] - *itr) <= d) {
      ans = max(ans, a[i] + *itr);
    }
  }

  cout << ans << endl;
  return 0;
}
