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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  string s;
  cin >> s;
  vector sumM(n, vector<ll>(3, 0)), sumX(n, vector<ll>(3, 0));

  rep(i, 0, n) {
    if (i != 0) {
      rep(j, 0, 3) { sumM[i][j] = sumM[i - 1][j]; }
    }
    if (s[i] == 'M') {
      sumM[i][a[i]]++;
    }
  }
  rrep(i, n - 1, 0) {
    if (i != n - 1) {
      rep(j, 0, 3) { sumX[i][j] = sumX[i + 1][j]; }
    }
    if (s[i] == 'X') {
      sumX[i][a[i]]++;
    }
  }

  // rep(i, 0, n) { printf("%d %d %d\n", sumM[i][0], sumM[i][1], sumM[i][2]); }
  // rep(i, 0, n) { printf("%d %d %d\n", sumX[i][0], sumX[i][1], sumX[i][2]); }

  ll ans = 0;
  rep(i, 0, n) {
    if (s[i] != 'E') continue;
    rep(j, 0, 3) {
      rep(k, 0, 3) {
        set<ll> s;
        s.insert(a[i]);
        s.insert(j);
        s.insert(k);
        ll tar = 3;
        rep(l, 0, 3) {
          if (s.find(l) == s.end()) {
            tar = (ll)l;
            break;
          }
        }
        ans += tar * sumM[i][j] * sumX[i][k];
      }
    }
  }

  cout << ans << endl;
  return 0;
}
