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
  int ans = 0;
  int i = 1, j = 2;
  rep(q, 0, 2 * n) {
    cout << "? " << i << " " << j << endl;
    string s;
    cin >> s;
    if (s == "Yes") {
      if (j == n) {
        ans += j - i;
        i++;
      } else {
        ++j;
      }
    } else {
      ans += j - i - 1;
      ++i;
      if (i == j) j = min(n, j + 1);
    }
    if (j >= n && i == j) break;
  }

  cout << "! " << ans << endl;
  return 0;
}
