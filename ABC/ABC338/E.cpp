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
  int n;
  cin >> n;
  vector<pair<int, int>> l(n * 2);
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if (a > b) swap(a, b);
    l[a] = {0, i};
    l[b] = {1, i};
  }
  stack<int> st;
  rep(i, 0, 2 * n) {
    auto [t, id] = l[i];
    if (t == 0) {
      st.push(id);
    } else {
      if (st.top() != id) {
        cout << "Yes" << endl;
        return 0;
      }
      st.pop();
    }
  }
  cout << "No" << endl;
  return 0;
}
