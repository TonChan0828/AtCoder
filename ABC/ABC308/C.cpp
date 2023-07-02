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
bool desc_asc(pair<long double, int> &left, pair<long double, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> ab(n);
  rep(i, 0, n) {
    long double a, b;
    cin >> a >> b;
    ab[i] = {a, a + b};
  }
  vector<int> p(n);
  rep(i, 0, n) p[i] = i;
  auto f = [&](int i, int j) {
    auto [ai, aj] = ab[i];
    auto [bi, bj] = ab[j];
    return (ll)ai * bj > (ll)aj * bi;
  };

  stable_sort(p.begin(), p.end(), f);
  rep(i, 0, n) { printf("%d ", p[i] + 1); }
  cout << endl;

  return 0;
}
