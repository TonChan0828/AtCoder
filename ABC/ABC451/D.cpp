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
  int n;
  cin >> n;

  ll t = 1;
  vector<int> p2;
  while (t <= 1e9) {
    p2.push_back(t);
    t *= 2;
  }
  vector<ll> tmp;
  auto dfs = [&](auto dfs, string s) -> void {
    for (int x : p2) {
      string t = s + to_string(x);
      ll tar = stoll(t);
      if (tar > 1e9) return;
      tmp.push_back(tar);
      dfs(dfs, t);
    }
  };

  dfs(dfs, "");
  sort(begin(tmp), end(tmp));

  vector<ll> ans;
  for (ll x : tmp)
    if (ans.empty() || ans.back() != x) ans.push_back(x);

  // rep(i, 0, 80) cout << ans[i] << " ";
  // cout << endl;
  cout << ans[n - 1] << endl;

  return 0;
}
