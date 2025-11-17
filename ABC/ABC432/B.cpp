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
  int x;
  cin >> x;
  vector<int> a;
  while (x > 0) {
    a.push_back(x % 10);
    x /= 10;
  }
  sort(begin(a), end(a));
  int ans = 1001001001;
  do {
    if (a[0] == 0) continue;
    int tar = 0;
    rep(i, 0, a.size()) {
      tar *= 10;
      tar += a[i];
    }
    ans = min(ans, tar);
  } while (next_permutation(begin(a), end(a)));
  cout << ans << endl;
  return 0;
}
