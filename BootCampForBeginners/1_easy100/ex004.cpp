#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  double X, ans;
  const double TAX = 1.08;
  X = ceil(N / 1.08);
  // cout << X << endl;
  ans = floor(X * TAX);
  // cout << X * TAX << endl;
  if (ans == N)
  {
    cout << X << endl;
  }
  else
  {
    cout << ":(" << endl;
  }
  return 0;
}

// void _main() {
//     cin >> N;
//     rep(X, 1, N + 1) {
//         double x = X;
//         x = (int)(x * 1.08);
//         if (x == N) {
//             cout << X << endl;
//             return;
//         }
//     }
//     cout << ":(" << endl;
