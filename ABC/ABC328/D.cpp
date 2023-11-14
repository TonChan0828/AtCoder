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
  string s;
  cin >> s;
  int n = s.size();
  stack<char> st;

  rep(i, 0, n) {
    st.push(s[i]);
    string t;

    int cnt = 0;
    while (!st.empty() && cnt < 3) {
      t.push_back(st.top());
      st.pop();
      ++cnt;
    }
    if (t == "CBA") continue;
    reverse(begin(t), end(t));
    for (char c : t) st.push(c);
  }

  string ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(begin(ans), end(ans));
  cout << ans << endl;
  return 0;
}
