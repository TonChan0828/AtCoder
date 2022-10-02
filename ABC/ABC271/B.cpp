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
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(n);
  rep(i, 0, n) {
    int l;
    cin >> l;
    rep(j, 0, l) {
      int t;
      cin >> t;
      a[i].push_back(t);
    }
  }
  rep(i, 0, q) {
    int s, t;
    cin >> s >> t;
    cout << a[s - 1][t - 1] << endl;
  }
  return 0;
}
