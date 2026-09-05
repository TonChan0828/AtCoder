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
  int n, k;
  cin >> n >> k;

  vector<vector<int>> ans;
  auto dfs = [&](auto dfs, vector<int>& v, int cnt, int sum) {
    if (cnt == 1) {
      // 重み1は残りsumから一意に決まるためループ不要
      int t = k - sum;
      if (t >= 0) {
        v.push_back(t);
        ans.push_back(v);
        v.pop_back();
      }
      return;
    }
    int t = 0;
    while (sum + t * cnt <= k) {
      v.push_back(t);
      dfs(dfs, v, cnt - 1, sum + t * cnt);
      v.pop_back();
      ++t;
    }
    return;
  };

  vector<int> tmp;
  dfs(dfs, tmp, n, 0);

  rep(i, 0, ans.size()) { reverse(begin(ans[i]), end(ans[i])); }
  sort(begin(ans), end(ans));
  rep(i, 0, ans.size()) {
    rep(j, 0, n) cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
