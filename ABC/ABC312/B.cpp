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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<string> tar1 =
                     {
                         "###.",
                         "###.",
                         "###.",
                         "....",
                     },
                 tar2 = {
                     "....",
                     ".###",
                     ".###",
                     ".###",
                 };

  vector<pair<int, int>> ans;
  rep(i, 0, n - 8) {
    rep(j, 0, m - 8) {
      // printf("%d %d\n", i, j);
      bool ok = true;

      rep(k, 0, 4) {
        rep(l, 0, 4) {
          if (!ok) continue;
          int kk = i + k, ll = j + l;
          if (s[kk][ll] != tar1[k][l]) ok = false;
        }
      }

      rep(k, 0, 4) {
        rep(l, 0, 4) {
          if (!ok) continue;
          int kk = i + k + 5, ll = j + l + 5;
          if (s[kk][ll] != tar2[k][l]) ok = false;
        }
      }

      if (ok) ans.push_back({i + 1, j + 1});
    }
  }
  sort(ans.begin(), ans.end());
  for (auto res : ans) {
    printf("%d %d\n", res.first, res.second);
  }
  return 0;
}
