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
  string t;
  cin >> t;
  int tsz = t.size();
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<int> cnt(n);
  rep(i, 0, n) cnt[i] = s[i].size();

  vector<int> ans;
  int num = 0;
  rep(i, 0, n) {
    if (abs(tsz - cnt[i]) > 1) continue;
    if (tsz - cnt[i] == 0) {
      int ng = 0;
      rep(j, 0, tsz) {
        if (t[j] != s[i][j]) {
          ng++;
        }
      }
      if (ng < 2) {
        num++;
        ans.push_back(i + 1);
      }
    } else if (tsz - cnt[i] == 1) {
      int pos = 0;
      rep(j, 0, tsz) {
        if (s[i][pos] == t[j]) {
          ++pos;
          if (pos == cnt[i]) {
            num++;
            ans.push_back(i + 1);
            break;
          }
        }
      }

    } else if (tsz - cnt[i] == -1) {
      int pos = 0;
      rep(j, 0, cnt[i]) {
        if (t[pos] == s[i][j]) {
          ++pos;
          if (pos == tsz) {
            num++;
            ans.push_back(i + 1);
            break;
          }
        }
      }
    }
  }
  cout << num << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
