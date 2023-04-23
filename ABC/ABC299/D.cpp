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
  vector<int> s(n, -1);
  int t = 1;
  cout << "? " << t << endl;
  cin >> s[t - 1];
  t = n;
  cout << "? " << t << endl;
  cin >> s[t - 1];
  int left = 1, right = n;
  rep(q, 0, 18) {
    if (left + 1 == right) break;
    int mid = (left + right) / 2;
    cout << "? " << mid << endl;
    cin >> s[mid - 1];
    if (s[left - 1] != s[mid - 1]) {
      right = mid;
      continue;
    }

    if (s[right - 1] != s[mid - 1]) {
      left = mid;
      continue;
    }
    left = mid;
  }

  cout << "! " << left << endl;
  return 0;
}
