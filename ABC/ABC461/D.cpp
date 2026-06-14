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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];

  auto f = [&](int k) -> ll {
    if (k == -1) return 0;
    ll res = 0;
    rep(li, 0, h) {
      vector<int> a(w);
      for (int ri = li; ri < h; ri++) {
        rep(j, 0, w) a[j] += s[ri][j] - '0';

        int l = 0, sum = 0;
        rep(r, 0, w) {
          sum += a[r];
          while (sum > k) {
            sum -= a[l];
            l++;
          }
          res += r - l + 1;
        }
      }
    }
    return res;
  };

  ll ans = f(k) - f(k - 1);
  cout << ans << endl;
  return 0;
}
