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
  string s;
  cin >> n >> s;
  vector<ll> num(1, 0);
  rep(i, 0, n) {
    if (i) num.push_back(num.back());
    num.back() += ll(i + 1) * ll(s[i] - '0');
  }

  // for (int x : num) cout << x << " ";
  // cout << endl;
  reverse(begin(num), end(num));

  vector<ll> ans(num.size() + 1, 0);
  rep(i, 0, num.size()) {
    ans[i] += num[i];
    ans[i + 1] += ans[i] / 10LL;
    ans[i] %= 10LL;
  }

  reverse(begin(ans), end(ans));
  rep(i, 0, ans.size()) {
    if (i == 0 && ans[0] == 0) continue;
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
