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
  string s;
  cin >> s;
  vector<int> x(4);
  rep(i, 0, 4) x[i] = s[i] - '0';

  if (x[0] == x[1] && x[0] == x[2] && x[0] == x[3]) {
    cout << "Weak\n";
  } else if ((x[0] + 1) % 10 == x[1] && (x[1] + 1) % 10 == x[2] &&
             (x[2] + 1) % 10 == x[3]) {
    cout << "Weak\n";
  } else {
    cout << "Strong\n";
  }
  return 0;
}
