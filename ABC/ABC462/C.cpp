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

  vector x(n + 1, vector<int>());
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    x[a].push_back(b);
  }
  rep(i, 0, n + 1) if (!x[i].empty()) sort(begin(x[i]), end(x[i]), greater());

  int ans = 0;
  int min_y = 1001001001;
  rep(i, 1, n + 1) {
    if (x[i].empty()) continue;
    for (int y : x[i]) {
      if (y <= min_y) {
        ans++;
        min_y = y;
      } else {
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
