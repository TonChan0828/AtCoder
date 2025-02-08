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
  int n3 = 1;
  rep(i, 0, n) n3 *= 3;
  string s;
  cin >> s;
  vector<vector<int>> a(n + 1);
  rep(i, 0, n3) a[0].push_back(s[i] - '0');
  rep(i, 0, n) {
    int sz = a[i].size() / 3;
    rep(j, 0, sz) {
      int cnt = 0;
      rep(k, 0, 3) {
        if (a[i][3 * j + k]) ++cnt;
      }
      if (cnt > 1) {
        a[i + 1].push_back(1);
      } else {
        a[i + 1].push_back(0);
      }
    }
  }
  // rep(i, 0, n + 1) {
  //   rep(j, 0, a[i].size()) cout << a[i][j] << " ";
  //   cout << endl;
  // }

  int tar = (a[n][0] + 1) % 2;

  auto dfs = [&](auto dfs, int i, int j) -> int {
    if (i == 0) {
      int cnt = 0;
      rep(k, 0, 3) if (a[i][j + k] == tar) cnt++;
      // cout << i << " " << j << " " << cnt << endl;

      return max(0, 2 - cnt);
    }

    vector<int> cnt(3);
    rep(k, 0, 3) {
      if (a[i][j + k] == tar) {
        cnt[k] = 0;
      } else {
        cnt[k] = dfs(dfs, i - 1, 3 * (j + k));
      }
    }
    sort(begin(cnt), end(cnt));
    // cout << i << " " << j << " " << cnt[0] + cnt[1] << endl;
    return cnt[0] + cnt[1];
  };

  cout << dfs(dfs, n - 1, 0) << endl;

  return 0;
}
