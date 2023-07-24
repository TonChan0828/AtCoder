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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    --a[i];
  }
  vector<bool> vis(n, false);
  bool ok = false;
  rep(i, 0, n) {
    if (vis[i]) continue;
    set<int> s;
    auto f = [&](auto f, int x) -> void {
      if (vis[x]) {
        ok = true;
        int cnt = 1;
        vector<int> ans{};
        ans.push_back(x);
        int y = a[x];
        while (y != x) {
          // cout << "  " << y << endl;
          ans.push_back(y);
          y = a[y];
          ++cnt;
        }
        cout << cnt << "\n";
        rep(i, 0, cnt) {
          if (i != 0) cout << " ";
          cout << ans[i] + 1;
        }
        cout << "\n";
        return;
      }
      vis[x] = true;
      s.insert(x);
      f(f, a[x]);
    };
    f(f, i);
    if (ok) return 0;
  }
  return 0;
}
