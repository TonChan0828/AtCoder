#include <bits/stdc++.h>
using namespace std;
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
  vector<vector<int>> g(n);
  rep(i, 1, n) {
    int b;
    cin >> b;
    --b;
    g[b].push_back(i);
  }

  vector<pair<ll, int>> grade(n);
  grade[0] = {0, 0};
  auto f = [&](auto f, int t) -> void {
    for (int x : g[t]) {
      grade[x] = {grade[t].first + 1, x};
      f(f, x);
    }
  };
  f(f, 0);
  // rep(i, 0, n) { cout << grade[i].first << " " << grade[i].second << endl; }

  sort(grade.begin(), grade.end(), greater());
  // rep(i, 0, n) { cout << grade[i].first << " " << grade[i].second << endl; }
  int sub = grade[0].first;
  vector<ll> ans(n, 0);
  rep(i, 0, n) {
    if (g[grade[i].second].size() == 0) {
      ans[grade[i].second] = 1;
      continue;
    }
    ll mini = INT_MAX;
    ll maxi = 0LL;
    for (int x : g[grade[i].second]) {
      chmin(mini, ans[x]);
      chmax(maxi, ans[x]);
      // cout << mini << " " << maxi << endl;
    }
    ans[grade[i].second] = maxi + mini + 1;
  }

  // rep(i, 0, n) cout << ans[i] << endl;

  cout << ans[0] << endl;

  return 0;
}
