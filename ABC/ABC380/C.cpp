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
  int n, k;
  cin >> n >> k;
  --k;
  string s;
  cin >> s;

  vector<int> zo, one;
  int tot = 1, o1 = ((s[0] == '1') ? 1 : 0);
  rep(i, 1, n) {
    if (s[i] == '0' && s[i - 1] == '1') {
      zo.push_back(tot);
      one.push_back(o1);
      tot = 0, o1 = 0;
    }

    if (s[i] == '1') ++o1;
    ++tot;
  }
  zo.push_back(tot);
  one.push_back(o1);

  rep(i, 0, zo.size()) {
    if (i == k) {
      rep(j, 0, zo[i]) {
        if (j < one[i]) {
          cout << 1;
        } else {
          cout << 0;
        }
      }

    } else {
      rep(j, 0, zo[i]) {
        if (j < zo[i] - one[i]) {
          cout << 0;
        } else {
          cout << 1;
        }
      }
    }
  }
  cout << endl;
  return 0;
}
