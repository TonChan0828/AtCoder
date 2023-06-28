#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ans(6);
  for (int i = 0; i < n; ++i) {
    double ma, mi;
    cin >> ma >> mi;

    if (ma >= 35) {
      ++ans[0];
    } else if (ma >= 30) {
      ++ans[1];
    } else if (ma >= 25) {
      ++ans[2];
    } else if (ma < 0) {
      ++ans[5];
    }

    if (mi >= 25) ++ans[3];
    if (ma >= 0 && mi < 0) ++ans[4];
  }
  for (int i = 0; i < 6; ++i) {
    if (i != 5)
      printf("%d ", ans[i]);
    else
      printf("%d\n", ans[i]);
  }
  cout << "\n";
  return 0;
}
