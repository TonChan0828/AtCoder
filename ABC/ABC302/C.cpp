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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  sort(s.begin(), s.end());

  do {
    // rep(i, 0, n) cout << s[i] << endl;
    bool ok = true;

    rep(i, 0, n - 1) {
      set<int> set;
      int cnt = 0;
      rep(j, 0, m) {
        rep(k, 0, m) {
          if (set.count(k)) continue;
          if (s[i][j] == s[i + 1][k]) {
            ++cnt;
            set.insert(k);
            break;
          }
        }
      }
      // cout << s[i] << " " << s[i + 1] << " " << cnt << endl;
      if (cnt + 1 != m) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
    // cout << endl;
  } while (next_permutation(s.begin(), s.end()));

  cout << "No" << endl;
  return 0;
}
