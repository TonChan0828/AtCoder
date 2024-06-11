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
  int b = 1;

  vector ans(n + 1, vector<string>());
  ans[0].push_back("#");
  rep(t, 1, n + 1) {
    ans[t].resize(b * 3);
    rep(i, 0, 3) {
      rep(j, 0, 3) {
        rep(k, 0, b) {
          rep(l, 0, b) {
            if (i == 1 && j == 1) {
              ans[t][i * b + k].push_back('.');
            } else {
              ans[t][i * b + k].push_back(ans[t - 1][k][l]);
            }
          }
        }
      }
    }
    b *= 3;
  }

  rep(i, 0, b) cout << ans[n][i] << "\n";
  return 0;
}
