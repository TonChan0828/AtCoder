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
  int n, m;
  cin >> n >> m;
  using P = pair<int, int>;
  vector<int> row(n), column(n);
  map<P, int> table;
  rep(t, 0, m) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    row[r] = t;
    column[c] = t;
    table[{r, c}] = t;
  }

  int ans = 0;
  for (auto [ij, t] : table) {
    auto [i, j] = ij;
    if (row[i] <= t && column[j] <= t) {
      ++ans;
      // cout << "o ";
    } else {
      // cout << "x ";
    }

    // cout << endl;
  }
  cout << ans << endl;
  return 0;
}
