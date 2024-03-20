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

using P = pair<int, int>;

int main() {
  int n, h, w;
  cin >> n >> h >> w;
  int hw = h * w;
  vector<P> ab(n);
  rep(i, 0, n) cin >> ab[i].first >> ab[i].second;

  auto dfs = [&](auto dfs, vector<vector<bool>> s, vector<int> used) -> bool {
    int si = -1, sj = -1;
    rep(i, 0, h) rep(j, 0, w) if (!s[i][j] && si == -1) si = i, sj = j;
    if (si == -1) {
      rep(i, 0, h) {
        rep(j, 0, w) { cerr << s[i][j] << " "; }
        cout << endl;
      }
      return true;
    }

    rep(ri, 0, n) {
      if (used[ri]) continue;
      auto [a, b] = ab[ri];
      rep(_, 0, 2) {
        swap(a, b);
        if (si + a > h || sj + b > w) continue;
        bool ok = true;
        auto ns = s;
        rep(i, 0, a) {
          rep(j, 0, b) {
            if (ns[si + i][sj + j]) ok = false;
            ns[si + i][sj + j] = true;
          }
        }
        if (!ok) continue;
        used[ri] = 1;
        if (dfs(dfs, ns, used)) return true;
        used[ri] = 0;
      }
    }

    return false;
  };

  if (dfs(dfs, vector(h, vector<bool>(w, false)), vector<int>(n, 0))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
