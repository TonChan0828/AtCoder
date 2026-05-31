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

using P = pair<int, char>;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(26);
    for (char c : s) a[c - 'a']++;

    priority_queue<P> q;
    rep(i, 0, 26) if (a[i]) q.push({a[i], (char)('a' + i)});

    P p = q.top();
    q.pop();
    if (p.first > (n + 1) / 2) {
      cout << "No\n";
      continue;
    }

    string ans = "";
    ans += p.second;
    if (p.first - 1 > 0) q.push({p.first - 1, p.second});
    while (!q.empty()) {
      P p = q.top();
      q.pop();
      if (p.second == ans.back()) {
        P p2 = q.top();
        q.pop();
        ans += p2.second;
        if (p2.first - 1 > 0) q.push({p2.first - 1, p2.second});
        ans += p.second;

      } else {
        ans += p.second;
      }
      if (p.first - 1 > 0) q.push({p.first - 1, p.second});
    }
    printf("Yes\n%s\n", ans.c_str());
  }

  return 0;
}
