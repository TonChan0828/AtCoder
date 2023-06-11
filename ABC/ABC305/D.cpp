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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  map<int, int> mp;
  int time = 0;
  mp[0] = 0;
  for (int i = 1; i < n; i += 2) {
    mp[a[i]] = time;
    time = time + a[i + 1] - a[i];
    mp[a[i + 1]] = time;
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int l, r;
    cin >> l >> r;
    auto li = lower_bound(a.begin(), a.end(), l);
    auto ri = lower_bound(a.begin(), a.end(), r);
    // cout << *li << " " << *ri << endl;
    int ll = mp[*li];
    --li;
    int ans = 0;
    if (ll != mp[*li]) {
      ++li;
      ans = *li - l;
    } else {
      ++li;
    }

    int rr = mp[*ri];
    --ri;
    ans += mp[*ri] - mp[*li];
    if (rr != mp[*ri]) {
      ans += r - *ri;
    }
    cout << ans << endl;
  }
  return 0;
}
