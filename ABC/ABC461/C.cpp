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
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> c(n);
  vector<ll> v(n);
  rep(i, 0, n) cin >> c[i] >> v[i], c[i]--;

  using P = pair<ll, int>;
  vector<P> vc(n);
  rep(i, 0, n) vc[i] = {v[i], c[i]};
  sort(begin(vc), end(vc), greater());
  vector<bool> used(n), color(n);
  ll ans = 0;
  int cnt = 0;
  rep(i, 0, n) {
    if (!color[vc[i].second]) {
      ans += vc[i].first;
      used[i] = true;
      color[vc[i].second] = true;
      ++cnt;
    }
    // cout << vc[i].first << " " << vc[i].second << endl;

    if (cnt == k) {
      cout << ans << endl;
      return 0;
    } else if (cnt == m)
      break;
  }

  rep(i, 0, n) {
    if (used[i]) continue;
    ans += vc[i].first;
    ++cnt;
    // cout << vc[i].first << " " << vc[i].second << endl;
    if (cnt == k) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
