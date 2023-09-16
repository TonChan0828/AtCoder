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
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, m) cin >> t[i];

  vector<int> cnts(2), cntt(2);
  rep(i, 0, n) cnts[s[i]]++;
  rep(i, 0, m) cntt[t[i]]++;
  if ((cntt[0] > 0 && cnts[0] == 0) || (cntt[1] > 0 && cnts[1] == 0)) {
    cout << -1 << endl;
    return 0;
  }

  bool change = false;
  int dist = INT_MAX;
  rep(i, 0, n) {
    if (s[0] != s[i]) {
      dist = min(dist, min(i, n - i));
    }
  }

  int ans = m;
  rep(i, 0, m) {
    if (i == 0) {
      if (t[i] != s[0]) {
        ans += dist;
        change = true;
      }
    } else {
      if (t[i] != t[i - 1]) {
        if (change) {
          ++ans;
        } else {
          ans += dist;
          change = true;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
