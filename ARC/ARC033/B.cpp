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
  int na, nb;
  cin >> na >> nb;
  set<int> a, b, all;
  rep(i, 0, na) {
    int aa;
    cin >> aa;
    a.insert(aa);
    all.insert(aa);
  }
  rep(i, 0, nb) {
    int bb;
    cin >> bb;
    b.insert(bb);
    all.insert(bb);
  }
  double total = 0, both = 0;
  for (int x : all) {
    ++total;
    auto ita = a.find(x);
    auto itb = b.find(x);
    if (ita != a.end() && itb != b.end()) ++both;
  }
  printf("%.10lf\n", both / total);

  return 0;
}
