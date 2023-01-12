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

// int main() {
//   double m;
//   cin >> m;
//   double km = m / 1000;
//   if (km < 0.1) {
//     cout << "00" << endl;
//   } else if (km <= 5) {
//     if (km < 1) cout << 0;
//     cout << (int)(km * 10) << endl;
//   } else if (km <= 30) {
//     cout << (int)(km + 50) << endl;
//   } else if (km <= 70) {
//     cout << (int)(km - 30) / 5 + 80 << endl;
//   } else {
//     cout << 89 << endl;
//   }
//   return 0;
// }

int main(void) {
  int m;
  cin >> m;

  if (m < 100) {
    cout << "00" << endl;
  } else if (m <= 5000) {
    {
      if (m < 1000) cout << 0;
      cout << m / 100 << endl;
    }
  } else if (m <= 30000) {
    cout << m / 1000 + 50 << endl;
  } else if (m <= 70000) {
    cout << (m - 30000) / 5000 + 80 << endl;
  } else {
    cout << 89 << endl;
  }
  return 0;
}
