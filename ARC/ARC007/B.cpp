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
  int n, m;
  cin >> n >> m;
  vector<int> c(n + 1);
  rep(i, 0, n + 1) c[i] = i;
  int now = 0;
  rep(i, 0, m) {
    int d;
    cin >> d;
    c[now] = c[d];
    now = d;
    // rep(j, 0, n + 1) cout << c[j];
    // cout << endl;
  }
  vector<int> ans(n + 1);
  rep(i, 0, n + 1) {
    if (i != now) ans[c[i]] = i;
  }
  rep(i, 1, n + 1) cout << ans[i] << endl;

  return 0;
}
