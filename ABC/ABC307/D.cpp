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
  int n;
  cin >> n;
  string s;
  cin >> s;

  stack<char> st;
  int lt = 0;
  rep(i, 0, n) {
    if (s[i] == ')') {
      if (!lt) {
        st.push(s[i]);
        continue;
      } else {
        char t = st.top();
        st.pop();
        while (t != '(') {
          t = st.top();
          st.pop();
        }
        --lt;
        continue;
      }
    }
    if (s[i] == '(') {
      ++lt;
    }
    st.push(s[i]);
  }
  string ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}
