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
  int T;
  cin >> T;

  while (T--) {
    int n;
    string s;
    cin >> n >> s;

    int zeroL = 0, zeroR = 0;
    int oneL = 0, oneR = 0;
    int l = 0, r = 0;
    rep(i, 0, n) {
      if (s[l] == s[i]) continue;
      r = i;
      if (s[l] == '0') {
        if (zeroR - zeroL < r - l) {
          zeroL = l, zeroR = r;
        }
      } else {
        if (oneR - oneL < r - l) {
          oneL = l, oneR = r;
        }
      }
      l = i;
    }
    r = n;
    if (s[l] == '0') {
      if (zeroR - zeroL < r - l) {
        zeroL = l, zeroR = r;
      }
    } else {
      if (oneR - oneL < r - l) {
        oneL = l, oneR = r;
      }
    }
    // cout << zeroL << " " << zeroR << endl;
    // cout << oneL << " " << oneR << endl;

    int one = 0, zero = 0;
    rep(i, 0, n) {
      if (!(zeroL <= i && i < zeroR)) {
        if (s[i] == '0')
          zero += 2;
        else
          zero += 1;
      }

      if (!(oneL <= i && i < oneR)) {
        if (s[i] == '1')
          one += 2;
        else
          one += 1;
      }
    }
    // cout << " " << zero << " " << one << endl;
    cout << min(zero, one) << "\n";
  }
  return 0;
}
