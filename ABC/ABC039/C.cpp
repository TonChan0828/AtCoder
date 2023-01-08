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
  string s;
  cin >> s;
  int white = 0;
  int nb = 0, nb2 = 0;
  rep(i, 0, s.size() - 1) {
    if (white == 2) {
      break;
    }
    if (s[i] == 'B') {
      if (white == 1) {
        ++nb2;
      } else {
        ++nb;
      }
    }
    if (s[i] == 'W' && s[i + 1] == 'W') ++white;
  }

  if (nb2 == 3) {
    if (nb == 0) {
      cout << "Mi" << endl;
    } else if (nb == 1) {
      cout << "Re" << endl;
    } else {
      cout << "Do" << endl;
    }
  } else {
    if (nb == 0) {
      cout << "Si" << endl;
    } else if (nb == 1) {
      cout << "La" << endl;
    } else if (nb == 2) {
      cout << "So" << endl;
    } else {
      cout << "Fa" << endl;
    }
  }

  return 0;
}
