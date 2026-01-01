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

using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  stack<int> st;
  rep(i, 0, n) {
    int a;
    cin >> a;
    st.push(a);
    if (st.size() > 3) {
      vector<int> v;
      rep(i, 0, 4) {
        v.push_back(st.top());
        st.pop();
      }
      if (v[0] == v[1] && v[0] == v[2] && v[0] == v[3]) {
        continue;
      } else {
        rrep(i, 3, 0) st.push(v[i]);
      }
    }
  }

  cout << st.size() << endl;
  return 0;
}
