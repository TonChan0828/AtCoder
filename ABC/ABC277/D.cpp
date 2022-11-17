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

// int main() {
//   ll n, m;
//   cin >> n >> m;
//   ll sum = 0;
//   ll ans = LONG_LONG_MAX;
//   vector<ll> a(n);
//   map<ll, ll> map;

//   rep(i, 0, n) {
//     cin >> a[i];
//     sum += a[i];
//     map[a[i]]++;
//   }
//   vector<set<ll>> l;
//   int t = 0;

//   set<ll> set;
//   for (auto x : map) {
//     if (set.count(x.first)) continue;
//     ll cnt = x.first;
//     ll tmp = 0;
//     while (map[cnt]) {
//       set.insert(cnt);
//       tmp += cnt * map[cnt];
//       ++cnt;
//       cnt %= m;
//     }
//     chmin(ans, sum - tmp);
//     // cout << tmp << endl;
//   }
//   cout << ans << endl;
//   return 0;
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  unsigned long long sum = 0;
  rep(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());

  // rep(i, 0, n) { cout << a[i] << " "; }
  // cout << endl;

  vector<pair<int, int>> vp;
  int l = 0, r = 0;
  rep(i, 1, n) {
    if (a[i] == a[i - 1] || a[i] == a[i - 1] + 1) {
      ++r;
    } else {
      vp.push_back({l, r});
      l = i;
      r = i;
    }
    // cout << l << " " << r << endl;
  }
  if ((a[n - 1] + 1) % m == a[0]) {
    if (vp.size() == 0) {
      cout << 0 << endl;
      return 0;
    } else {
      vp[0].first = l;
    }
  } else {
    vp.push_back({l, r});
  }
  // rep(i, 0, vp.size()) { cout << vp[i].first << " " << vp[i].second << endl;
  // }

  // cout << sum << endl;
  unsigned long long ans = 2 * pow(10, 15);
  rep(i, 0, vp.size()) {
    int l = vp[i].first;
    int r = vp[i].second;
    unsigned long long tmp = 0;
    int cnt = 0;
    if (l <= r) {
      cnt = r - l + 1;
    } else {
      cnt = n - l + r + 1;
    }
    // cout << cnt << endl;
    rep(j, l, l + cnt) { tmp += a[j % n]; }
    // cout << tmp << endl;
    chmin(ans, sum - tmp);
  }
  cout << ans << endl;
  return 0;
}
