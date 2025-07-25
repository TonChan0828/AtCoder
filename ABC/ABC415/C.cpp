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
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    set<int> st;
    st.insert(0);
    rep(i, 1, s.size() + 1) {
      if (s[i - 1] == '1') continue;
      rep(j, 0, n) {
        if (i & (1 << j)) {
          if (st.count(i - (1 << j))) {
            st.insert(i);
            break;
          }
        }
      }
    }
    // for (int x : st) cout << x << " ";
    // cout << endl;
    if (st.count((1 << n) - 1)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
