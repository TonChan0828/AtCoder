#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  rep(i, 0, n) {
    int l;
    cin >> l;
    rep(j, 0, l) {
      int aa;
      cin >> aa;

      a[i].push_back(aa);
    }
  }
  sort(begin(a), end(a));
  // rep(i, 0, n) {
  //   for (int j : a[i]) {
  //     cout << j << " ";
  //   }
  //   cout << endl;
  // }
  int ans = n;
  int i = 0;
  rep(j, 1, n) {
    if (a[i].size() != a[j].size()) {
      i = j;
      continue;
    }
    bool ok = true;
    rep(k, 0, a[i].size()) {
      if (a[i][k] != a[j][k]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      --ans;
    } else {
      i = j;
    }
  }
  cout << ans << endl;
  return 0;
}
