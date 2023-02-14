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
  vector<char> t(3);
  t[0] = 'a', t[1] = 'b', t[2] = 'c';
  vector<int> ans(n, 0);

  int total = 1;
  rep(i, 0, n) { total *= 3; }

  rep(i, 0, total) {
    rep(j, 0, n) { cout << t[ans[j] % 3]; }
    // rep(j, 0, n) { cout << ans[j]; }
    cout << endl;
    ++ans[n - 1];
    rrep(j, n - 1, 1) {
      if (ans[j] == 3) {
        ans[j] = 0;
        ++ans[j - 1];
      }
    }
  }
  return 0;
}
