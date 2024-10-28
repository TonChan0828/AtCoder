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

using P = pair<int, int>;
const int di[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dj[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
  ll n;
  int m;
  cin >> n >> m;

  set<P> s;
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    s.insert({a, b});
    rep(j, 0, 8) {
      int ni = a + di[j], nj = b + dj[j];
      if (ni < 0 || nj < 0 || ni > n - 1 || nj > n - 1) continue;
      s.insert({ni, nj});
    }
  }

  ll sz = s.size();
  cout << n * n - sz << endl;
  return 0;
}
