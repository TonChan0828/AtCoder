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
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> a(n);
  rep(i, 0, n) {
    int x, y, h;
    cin >> x >> y >> h;
    a[i] = {{x, y}, h};
  }

  rep(x, 0, 101) {
    rep(y, 0, 101) {
      bool ok = true;
      bool start = true;
      int hi = 0;
      rep(i, 0, n) {
        if (a[i].second == 0) continue;
        hi = a[i].second + abs(x - a[i].first.first) +
             abs(y - a[i].first.second);
        break;
      }
      rep(i, 0, n) {
        int tmp = hi - abs(x - a[i].first.first) - abs(y - a[i].first.second);
        if (max(tmp, 0) != a[i].second) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << x << " " << y << " " << hi << endl;
        // cout << x << y << hi << endl;
        return 0;
      }
    }
  }
  return 0;
}
