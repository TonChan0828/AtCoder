#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int N, K;
  cin >> N >> K;
  int x[101];
  rep(i, N)
  {
    cin >> x[i];
  }

  int sum = 0;
  int a, b;
  rep(i, N)
  {
    a = x[i] - 0;
    b = K - x[i];
    if (a > b)
    {
      sum += b;
    }
    else
    {
      sum += a;
    }
  }
  cout << 2 * sum << endl;
  return 0;
}
