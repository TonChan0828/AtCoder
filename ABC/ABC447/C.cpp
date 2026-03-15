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
  string s, t;
  cin >> s >> t;
  int sn = s.size(), tn = t.size();

  int i = 0, j = 0;
  int ans = 0;
  while (i < sn && j < tn) {
    if (s[i] == t[j]) {
      ++i;
    } else {
      if (t[j] == 'A') {
        ++ans;
      } else {
        while (i < sn && s[i] != t[j]) {
          if (s[i] != 'A') {
            cout << -1 << endl;
            return 0;
          }
          ++i;
          ++ans;
        }
        if (i == sn) {
          ans = -1;
          break;
        }
        ++i;
      }
    }
    ++j;
    // cout << i << " " << j << "  " << ans << endl;
  }
  while (j < tn) {
    if (t[j] == 'A') {
      ++ans;
    } else {
      ans = -1;
      break;
    }
    j++;
    // cout << i << " " << j << "  " << ans << endl;
  }

  while (i < sn) {
    if (s[i] == 'A') {
      ++ans;
    } else {
      ans = -1;
      break;
    }
    i++;
    // cout << i << " " << j << "  " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
