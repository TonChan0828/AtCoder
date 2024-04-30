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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  stack<int> st;

  rep(i, 0, n) {
    st.push(a[i]);
    while (st.size() > 1) {
      vector<int> t(2);
      t[0] = st.top();
      st.pop();
      t[1] = st.top();
      st.pop();
      // cout << t[0] << " " << t[1] << endl;
      if (t[0] == t[1]) {
        st.push(t[0] + 1);
      } else {
        st.push(t[1]);
        st.push(t[0]);
        break;
      }
    }
  }

  cout << st.size() << endl;
  return 0;
}
