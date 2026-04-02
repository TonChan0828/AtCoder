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

using P = pair<ll, int>;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    priority_queue<P, vector<P>, greater<P>> q;
    vector<ll> r(n);
    rep(i, 0, n) {
      cin >> r[i];
      q.push({r[i], i});
    }

    ll ans = 0;
    vector<bool> vis(n);
    while (!q.empty()) {
      auto [v, p] = q.top();
      q.pop();
      // cout << "  " << v << " " << p << endl;
      if (vis[p]) continue;
      vis[p] = true;
      if (p - 1 >= 0 && !vis[p - 1]) {
        ans += max(r[p - 1] - (v + 1), 0LL);
        r[p - 1] = v + 1;
        q.push({v + 1, p - 1});
      }

      if (p + 1 < n && !vis[p + 1]) {
        ans += max(r[p + 1] - (v + 1), 0LL);
        r[p + 1] = v + 1;
        q.push({v + 1, p + 1});
      }

      // for (int x : r) printf("%2d ", x);
      // cout << endl;
    }
    cout << ans << "\n";
  }

  return 0;
}
