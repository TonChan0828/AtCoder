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
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m) cin >> a[i] >> b[i], --a[i], --b[i];

  set<pair<int, int>> ans;

  auto judge = [&](int x, int y) -> bool {
    rep(i, 0, m) {
      if (a[i] != x && b[i] != x && a[i] != y && b[i] != y) return false;
    }
    return true;
  };

  auto f = [&](int x) {
    int idx = -1;
    rep(i, 0, m) {
      if (a[i] != x && b[i] != x) {
        idx = i;
        break;
      }
    }

    if (idx == -1) {
      rep(y, 0, n) {
        if (x == y) continue;
        ans.insert({min(x, y), max(x, y)});
      }
    } else {
      if (judge(x, a[idx])) ans.insert({min(x, a[idx]), max(x, a[idx])});
      if (judge(x, b[idx])) ans.insert({min(x, b[idx]), max(x, b[idx])});
    }
  };

  f(a[0]);
  f(b[0]);

  cout << ans.size() << endl;
  return 0;
}
