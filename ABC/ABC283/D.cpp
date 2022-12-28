#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  string s;
  cin >> s;
  stack<char> st;
  set<char> set;
  rep(i, 0, s.size()) {
    if (s[i] != ')') {
      st.push(s[i]);
      if (s[i] != '(') {
        if (set.count(s[i])) {
          cout << "No" << endl;
          return 0;
        }
        set.insert(s[i]);
      }
    } else {
      while (st.top() != '(') {
        set.erase(st.top());
        st.pop();
      }
      st.pop();
    }
  }
  cout << "Yes" << endl;
  return 0;
}
