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
  vector<string> s(9);
  rep(i, 0, 9) cin >> s[i];
  vector<pair<int, int>> p;
  rep(i, 0, 9) {
    rep(j, 0, 9) {
      if (s[i][j] == '#') p.push_back({i, j});
    }
  }
  ll ans = 0;
  int size = p.size();
  // cout << size << endl;
  rep(i, 0, size - 3) {
    rep(j, i + 1, size - 2) {
      rep(k, j + 1, size - 1) {
        rep(l, k + 1, size) {
          int a = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
          int b = abs(p[i].first - p[k].first) + abs(p[i].second - p[k].second);
          int c = abs(p[j].first - p[l].first) + abs(p[j].second - p[l].second);
          int d = abs(p[k].first - p[l].first) + abs(p[k].second - p[l].second);
          if (a == b && a == c && a == d) {
            double tha =
                ((p[j].first - p[i].first) * (p[k].first - p[i].first) +
                 (p[j].second - p[i].second) * (p[k].second - p[i].second));
            // double thb =
            //     ((p[j].first - p[l].first) * (p[j].first - p[l].first) +
            //      (p[j].second - p[l].second) * (p[k].second - p[l].second));

            // cout << tha << endl;
            if (tha == 0) ++ans;
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
