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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];

  map<int, int> mp;
  vector<bool> used(n, false);
  auto dfs = [&](auto dfs, int now) -> bool {
    if (mp[now] != 0) {
      if (mp[now] == 1) {
        return true;
      } else {
        return false;
      }
    }

    bool res = false;
    rep(i, 0, n - 1) {
      if (used[i]) continue;
      used[i] = true;
      now += 1 << i;
      rep(j, i + 1, n) {
        if (used[j]) continue;
        if (a[i] == a[j] || b[i] == b[j]) {
          used[j] = true;
          now += 1 << j;
          res |= !dfs(dfs, now);
          now -= 1 << j;
          used[j] = false;
        }
      }
      now -= 1 << i;
      used[i] = false;
    }
    if (res) {
      mp[now] = 1;
    } else {
      mp[now] = -1;
    }

    return res;
  };

  if (dfs(dfs, 0)) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
  return 0;
}
