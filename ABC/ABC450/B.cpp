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
  const int INF = 1001001001;
  vector cost(n - 1, vector<int>(n, INF));
  rep(i, 0, n - 1) {
    rep(j, i + 1, n) { cin >> cost[i][j]; }
  }

  rep(a, 0, n - 1) {
    rep(c, a + 1, n) {
      rep(b, a + 1, c) {
        if (cost[a][c] > cost[a][b] + cost[b][c]) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }

  cout << "No\n";
  return 0;
}
