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
  string s;
  cin >> s;
  int Q;
  cin >> Q;
  vector<ll> k(Q);
  rep(i, 0, Q) cin >> k[i], --k[i];

  ll n = s.size();
  vector c(n, vector<char>(2));
  rep(i, 0, n) {
    c[i][0] = s[i];
    if (islower(s[i])) {
      c[i][1] = toupper(s[i]);
    } else {
      c[i][1] = tolower(s[i]);
    }
  }

  rep(i, 0, Q) {
    ll tar = k[i] % n;
    unsigned long long num = 1;
    ll pos = k[i] / n;
    // cout << tar << " " << pos << " ";
    while (num * 2 <= pos) {
      num *= 2LL;
    }

    // cout << num << " ";

    int cnt = 0;
    while (pos > 0) {
      ++cnt;
      pos -= num;
      while (num > pos) num /= 2LL;
    }

    // cout << pos << " " << cnt << " ";
    cout << c[tar][cnt % 2] << " ";
    // cout << endl;
  }

  cout << endl;
  return 0;
}
