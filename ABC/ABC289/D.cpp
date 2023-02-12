#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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
  int m;
  cin >> m;
  vector<int> b(m);
  rep(i, 0, m) cin >> b[i];
  int x;
  cin >> x;

  vector<int> dp(x + 1, 0);
  vector<int> ave(x + 1, 0);
  rep(i, 0, m) ave[b[i]] = 1;
  dp[0] = 1;
  rep(j, 0, x + 1) {
    if (ave[j]) {
      dp[j] = 0;
    } else {
      rep(i, 0, n) {
        if (j >= a[i]) {
          dp[j] |= dp[j - a[i]];
        }
      }
    }
  }

  if (dp[x]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
