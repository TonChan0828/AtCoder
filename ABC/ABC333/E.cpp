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
  vector<int> t(n), x(n);
  rep(i, 0, n) cin >> t[i] >> x[i];
  vector p(n + 1, 0);
  vector<bool> flg(n, false);
  int ans = 0, cnt = 0;

  rrep(i, n - 1, 0) {
    if (t[i] == 1) {
      if (p[x[i]] < 0) {
        ++p[x[i]];
        --cnt;
        flg[i] = true;
      }
    } else {
      --p[x[i]];
      ++cnt;
      chmax(ans, cnt);
    }
  }

  rep(i, 0, n + 1) {
    if (p[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  rep(i, 0, n) {
    if (t[i] == 1) {
      if (flg[i])
        cout << 1;
      else
        cout << 0;
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}
