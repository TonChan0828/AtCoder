#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int N;
  cin >> N;
  vector<int> d(100000);
  rep(i, 0, N)
  {
    cin >> d[i];
  }
  sort(d.begin(), d.end(), greater<>());

  // rep(i, 0, N)
  // {
  //   cout << d[i];
  // }
  int ans = 0;
  if (d[(N / 2) - 1] == d[(N / 2)])
  {
    ans = 0;
  }
  else
  {
    ans = d[(N / 2) - 1] - d[(N / 2)];
  }

  cout << ans << endl;
  return 0;
}
