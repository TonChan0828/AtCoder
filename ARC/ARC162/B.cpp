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
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];
  vector<pair<int, int>> ans;
  rep(i, 0, n - 1) {
    if (p[i] == i + 1) continue;
    vector<int> tmp;
    rep(j, i + 1, n) {
      if (p[j] == i + 1) {
        if (j < n - 1) {
          tmp = {p[j], p[j + 1]};
          p.erase(p.begin() + j, p.begin() + j + 2);
          p.insert(p.begin() + i, tmp.begin(), tmp.end());
          ans.push_back({j + 1, i});
        } else {
          if (i == n - 2) {
            cout << "No" << endl;
            return 0;
          }
          ans.push_back({n - 1, n - 3});
          swap(p[n - 3], p[n - 2]);
          swap(p[n - 2], p[n - 1]);
          // rep(i, 0, n) printf("t%d ", p[i]);
          // cout << endl;
          ans.push_back({j, i});
          tmp = {p[j - 1], p[j]};
          p.erase(p.begin() + j - 1, p.begin() + j + 1);
          p.insert(p.begin() + i, tmp.begin(), tmp.end());
        }
        break;
      }
    }
    // rep(i, 0, n) printf("%d ", p[i]);
    // cout << endl;
  }
  bool ok = true;
  rep(i, 0, n) {
    if (p[i] != i + 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
      printf("%d %d\n", i, j);
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
