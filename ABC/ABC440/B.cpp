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
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i];
  int m = 0;
  rep(i, 0, n) {
    if (t[m] < t[i]) m = i;
  }

  vector<int> ans(3, m);
  rep(i, 0, n) {
    if (t[i] < t[ans[0]]) {
      ans[2] = ans[1];
      ans[1] = ans[0];
      ans[0] = i;
    } else if (t[i] < t[ans[1]]) {
      ans[2] = ans[1];
      ans[1] = i;
    } else if (t[i] < t[ans[2]]) {
      ans[2] = i;
    }
  }
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;
  return 0;
}
