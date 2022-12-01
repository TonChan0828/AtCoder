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
  int n, q;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> t(n + 1);
  rep(i, 0, n) {
    cin >> a[i];
    t[a[i]].push_back(i + 1);
  }

  cin >> q;
  rep(i, 0, q) {
    int l, r, x;
    cin >> l >> r >> x;
    auto low = lower_bound(t[x].begin(), t[x].end(), l);
    auto high = upper_bound(t[x].begin(), t[x].end(), r);
    int sz = high - low;
    cout << sz << endl;
  }
  return 0;
}
