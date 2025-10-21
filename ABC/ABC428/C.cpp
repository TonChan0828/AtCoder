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
  int Q;
  cin >> Q;

  vector<int> a(1), b(1);

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      char c;
      cin >> c;
      if (c == '(') {
        a.push_back(a.back() + 1);
      } else {
        a.push_back(a.back() - 1);
      }
      b.push_back(min(b.back(), a.back()));
    } else {
      a.pop_back();
      b.pop_back();
    }
    if (a.back() == 0 && b.back() == 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
