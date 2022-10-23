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
  string s;
  cin >> s;
  vector<pair<int, int>> a;
  int cnt = 0;
  int t = s[0];
  rep(i, 0, n) {
    if (t != s[i]) {
      a.push_back({t, cnt});
      t = s[i];
      cnt = 1;
    } else {
      ++cnt;
    }
  }
  a.push_back({t, cnt});

  int ans = 0;
  cnt = 0;
  int l = 0, r = 0;
  int sum = 0;
  rep(r, 0, a.size()) {
    sum += a[r].second;
    if (a[r].first == '0') ++cnt;
    if (cnt > k) {
      while (cnt > k) {
        sum -= a[l].second;
        if (a[l].first == '0') --cnt;
        ++l;
        // cout << sum << endl;
      }
    }
    // cout << sum << endl;
    ans = max(ans, sum);
  }

  cout << ans << endl;
  return 0;
}
