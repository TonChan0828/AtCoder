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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> rl;
  rep(i, 0, n) {
    int l, r;
    cin >> l >> r;
    rl.emplace_back(r, l);
  }
  sort(rl.begin(), rl.end());

  const int INF = 1001001001;
  auto judge = [&](int w) {
    int r_max = -INF, num = 0;
    for (auto [r, l] : rl) {
      r += w;
      if (r_max <= l) {
        num++;
        r_max = r;
      }
    }
    return num >= k;
  };
  int ac = 0, wa = INF;
  while (ac + 1 < wa) {
    int wj = (ac + wa) / 2;
    if (judge(wj))
      ac = wj;
    else
      wa = wj;
  }
  if (ac == 0) ac = -1;
  cout << ac << endl;

  return 0;
}
