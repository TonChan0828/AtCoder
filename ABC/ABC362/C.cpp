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
  vector<ll> l(n), r(n);
  rep(i, 0, n) cin >> l[i] >> r[i];

  vector<int> ans(n);
  ll sum = 0;
  rep(i, 0, n) {
    ans[i] = (r[i] + l[i]) / 2LL;
    sum += ans[i];
  }
  // rep(i, 0, n) cout << ans[i] << " ";
  // cout << sum << endl;

  rep(i, 0, n) {
    if (sum < 0) {
      ll d = min(llabs(sum), r[i] - ans[i]);
      sum += d;
      ans[i] += d;
    } else if (sum > 0) {
      ll d = min(sum, ans[i] - l[i]);
      sum -= d;
      ans[i] -= d;
    }
    if (sum == 0) break;
  }

  if (sum) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  rep(i, 0, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
