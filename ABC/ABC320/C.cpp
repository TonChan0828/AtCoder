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
  int m;
  cin >> m;
  vector<string> s(3);
  rep(i, 0, 3) cin >> s[i];

  vector<int> order = {0, 1, 2};
  int ans = INT_MAX;

  auto f = [&](vector<int> o) -> void {
    rep(i, 0, m) {
      rep(j, 1, m + 1) {
        rep(k, 1, m + 1) {
          if (s[o[0]][i] == s[o[1]][(i + j) % m] &&
              s[o[0]][i] == s[o[2]][(i + j + k) % m]) {
            ans = min(ans, i + j + k);
          }
        }
      }
    }
  };

  do {
    f(order);
  } while (next_permutation(begin(order), end(order)));
  cout << (ans == INT_MAX ? -1 : ans) << endl;
  return 0;
}
