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
  map<string, int> m;
  m["tourist"] = 3858;
  m["ksun48"] = 3679;
  m["Benq"] = 3658;
  m["Um_nik"] = 3648;
  m["apiad"] = 3638;
  m["ecnerwala"] = 3613;
  m["mnbvmar"] = 3555;
  m["newbiedmy"] = 3516;
  m["semiexp"] = 3481;
  m["Stonefeang"] = 3630;
  string s;
  cin >> s;
  cout << m[s] << endl;

  return 0;
}
