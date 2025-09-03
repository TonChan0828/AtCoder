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
  string s;
  cin >> n >> s;

  vector v(2, vector<int>());
  rep(i, 0, 2 * n) {
    if (s[i] == 'A') {
      v[0].push_back(i);
    } else {
      v[1].push_back(i);
    }
  }

  auto cal = [&](vector<vector<int>> v) -> ll {
    ll ans = 0;
    vector<int> cnt(2);
    cnt[0] = 0, cnt[1] = 1;
    rep(i, 0, 2 * n) {
      int x = i % 2, y = i / 2;

      ans += max(i, v[x][y]) - i;
      // cout << " " << max(i, v[x][y]) << " " << ans << endl;
    }
    return ans;
  };

  ll res = cal(v);
  swap(v[0], v[1]);
  res = min(res, cal(v));

  cout << res << endl;
  return 0;
}
