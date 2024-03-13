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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];
  map<int, int> mp;
  set<int> s;
  int ans = 0;
  rep(i, 0, n) {
    s.insert(c[i]);
    mp[c[i]]++;
    if (i >= k) {
      mp[c[i - k]]--;
      if (!mp[c[i - k]]) {
        s.erase(c[i - k]);
      }
    }
    // for (int x : s) cout << x << " ";
    // cout << endl;
    ans = max(ans, (int)s.size());
  }

  cout << ans << endl;
  return 0;
}
