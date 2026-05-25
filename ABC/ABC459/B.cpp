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
  rep(i, 0, n) {
    string s;
    cin >> s;
    int d = s[0] - 'a';
    if (d < 3) {
      cout << 2;
    } else if (d < 6) {
      cout << 3;
    } else if (d < 9) {
      cout << 4;
    } else if (d < 12) {
      cout << 5;
    } else if (d < 15) {
      cout << 6;
    } else if (d < 19) {
      cout << 7;
    } else if (d < 22) {
      cout << 8;
    } else {
      cout << 9;
    }
  }
  cout << endl;
  return 0;
}
