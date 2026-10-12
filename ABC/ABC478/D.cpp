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

using P = pair<int, int>;
int main() {
  int n, Q;
  cin >> n >> Q;

  map<int, vector<P>> mp;
  rep(qi, 0, Q) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --x;
    mp[x].push_back({l, r});
  }
  for (auto& [_, v] : mp) {
    sort(begin(v), end(v));
    // cout << _ << " :";
    // for (const auto& [x, y] : v) {
    //   cout << '(' << x << ',' << y << "),";
    // }
    // cout << '\n';
  }

  vector<int> cnt(n + 1);
  for (auto [k, v] : mp) {
    int l = v[0].first, r = v[0].second;
    rep(i, 0, v.size()) {
      if (r < v[i].first) {
        cnt[l]++, cnt[r]--;
        // cout << k << " " << l << " " << r << endl;
        l = v[i].first, r = v[i].second;
      } else {
        r = max(r, v[i].second);
      }
    }
    cnt[l]++, cnt[r]--;
    // cout << k << " " << l << " " << r << endl;
  }

  rep(i, 0, n) {
    if (i) cnt[i] += cnt[i - 1];
    cout << cnt[i] << " ";
  }
  cout << endl;
  return 0;
}
