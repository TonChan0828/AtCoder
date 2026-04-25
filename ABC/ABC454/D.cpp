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
    string a, b;
    cin >> a >> b;

    auto reduce = [](const string& s) {
      stack<char> st;
      for (char c : s) {
        st.push(c);
        if (c == ')') {
          string tmp;
          for (int i = 0; i < 4 && !st.empty(); i++) {
            tmp += st.top();
            st.pop();
          }
          if (tmp == ")xx(") {
            st.push('x');
            st.push('x');
          } else {
            reverse(begin(tmp), end(tmp));
            for (char ch : tmp) st.push(ch);
          }
        }
      }
      string result;
      while (!st.empty()) {
        result += st.top();
        st.pop();
      }
      return result;
    };

    cout << (reduce(a) == reduce(b) ? "Yes" : "No") << "\n";
  }
  return 0;
}
