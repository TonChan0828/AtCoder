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
  vector<vector<int>> a(n);
  rep(i, 0, m) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int x;
      cin >> x;
      --x;
      a[x].push_back(i);
    }
  }
  rep(i, 0, n - 1) {
    vector<bool> t(n, false);
    t[i] = true;
    rep(j, 0, a[i].size()) {
      bool flag = false;
      rep(k, i + 1, n) {
        int count = std::count(a[k].begin(), a[k].end(), a[i][j]);
        if (count >= 1) {
          t[k] = true;
        }
      }
    }
    rep(j, i, n) {
      if (!t[j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
