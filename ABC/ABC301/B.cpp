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

  vector<int> ans;
  rep(i, 0, n - 1) {
    ans.push_back(a[i]);
    if (abs(a[i] - a[i + 1]) != 1) {
      if (a[i] > a[i + 1]) {
        rrep(j, a[i] - 1, a[i + 1] + 1) { ans.push_back(j); }
      } else {
        rep(j, a[i] + 1, a[i + 1]) { ans.push_back(j); }
      }
    }
  }

  ans.push_back(a[n - 1]);

  rep(i, 0, ans.size()) {
    if (i != 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
