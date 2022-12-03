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
  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << -1 << endl;
    return 0;
  } else if (s == t) {
    cout << 0 << endl;
    return 0;
  }

  int sz = s.size();
  deque<char> sd, td;
  rep(i, 0, sz) {
    sd.push_back(s[i]);
    td.push_back(t[i]);
  }

  rep(i, 0, sz) {
    sd.push_front(sd[sz - 1]);
    sd.erase(sd.end() - 1);
    // rep(j, 0, s.size()) cout << sd[j];
    // cout << endl;
    if (sd == td) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
