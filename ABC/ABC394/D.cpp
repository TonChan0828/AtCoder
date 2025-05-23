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
  st.push(s[0]);
  rep(i, 1, n) {
    if (st.empty()) {
      st.push(s[i]);
      continue;
    }
    if ((st.top() == '(' && s[i] == ')') || (st.top() == '<' && s[i] == '>') ||
        (st.top() == '[' && s[i] == ']')) {
      st.pop();
    } else {
      st.push(s[i]);
    }
  }
  if (st.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No\n";
  }
  return 0;
}
