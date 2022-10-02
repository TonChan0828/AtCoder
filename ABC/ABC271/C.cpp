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
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
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
  vector<bool> vol(n + 2, false);
  int sold = 0;
  rep(i, 0, n) {
    cin >> a[i];
    if (a[i] >= vol.size())
      sold++;
    else if (vol[a[i]])
      sold++;
    else
      vol[a[i]] = true;
  }

  int l = 1;
  int r = n + 1;
  while (true) {
    while (vol[l]) l++;
    while (r != 0 && !vol[r]) r--;
    if (sold >= 2) {
      sold -= 2;
      vol[l] = true;
    } else {
      if (l >= r) break;
      vol[r] = false;
      sold++;
    }
  }
  cout << l - 1 << endl;
  return 0;
}
