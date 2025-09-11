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
  int n, k;
  cin >> n >> k;
  int sz = 1;

  vector v(n + 1, vector<int>());
  v[0].push_back(k);
  rep(i, 1, n + 1) {
    rep(j, 0, sz) {
      if (v[i - 1][j] % 2) {
        v[i].push_back(v[i - 1][j] / 2);
        v[i].push_back(v[i - 1][j] / 2 + 1);
      } else {
        v[i].push_back(v[i - 1][j] / 2);
        v[i].push_back(v[i - 1][j] / 2);
      }
    }
    sz *= 2;
  }
  if (k % sz) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }
  for (int x : v[n]) cout << x << " ";
  cout << "\n";
  return 0;
}
