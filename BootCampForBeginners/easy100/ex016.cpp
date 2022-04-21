#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int N;
  cin >> N;
  map<int, int> A, At;
  rep(i, 0, N)
  {
    cin >> A[i];
  }

  for (const auto &[key, value] : A)
  {
    At.emplace(value, key);
  }
  for (const auto &[key, value] : At)
  {
    cout << (value + 1) << " ";
  }
  cout << endl;

  return 0;
}
