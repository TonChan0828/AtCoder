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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);

  rep(i, 0, 3 * n) {
    int tmp;
    cin >> tmp;
    --tmp;
    a[tmp].push_back(i);
  }
  vector<pair<int, int>> ans(n);
  rep(i, 0, n) {
    sort(a[i].begin(), a[i].end());
    ans[i] = {a[i][1], i + 1};
  }
  sort(ans.begin(), ans.end());
  rep(i, 0, n) { printf("%d ", ans[i].second); }
  cout << endl;

  return 0;
}
