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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(m);
  vector a(m, vector<int>());
  vector<char> r(m);
  rep(i, 0, m) {
    cin >> c[i];
    rep(j, 0, c[i]) {
      int aa;
      cin >> aa;
      a[i].push_back(--aa);
    }
    cin >> r[i];
  }

  int ans = 0;
  rep(tar, 0, 1 << n) {
    bool ok = true;
    rep(i, 0, m) {
      int cnt = 0;
      rep(j, 0, c[i]) {
        if (1 & (tar >> a[i][j])) ++cnt;
      }
      if ((cnt >= k) != (r[i] == 'o')) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++ans;
      // rep(i, 0, n) {
      //   if (1 & tar >> i) {
      //     cout << "1";
      //   } else {
      //     cout << "0";
      //   }
      // }
      // cout << endl;
    }
  }

  cout << ans << endl;
  return 0;
}
