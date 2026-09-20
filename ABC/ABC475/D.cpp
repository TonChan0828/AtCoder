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
  string s;
  cin >> s;

  int n = 1e8;
  vector<bool> num(n, true);

  num[0] = false, num[1] = false;
  rep(i, 2, n) {
    if (num[i] == false) continue;
    ll tar = i + i;
    while (tar < n) {
      num[tar] = false;
      tar += i;
    }
  }

  vector<int> p;
  rep(i, 0, n) if (num[i]) p.push_back(i);
  vector<string> prime;
  for (int x : p) {
    prime.push_back(to_string(x));
  }

  for (string t : prime) {
    if (t.size() != s.size()) continue;
    bool ok = true;
    rep(i, 0, s.size()) {
      rep(j, i + 1, s.size()) {
        if (s[i] == s[j]) {
          if (t[i] != t[j]) {
            ok = false;
            break;
          }
        } else {
          if (t[i] == t[j]) {
            ok = false;
            break;
          }
        }
      }
      if (!ok) break;
    }
    if (ok) {
      cout << t << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
