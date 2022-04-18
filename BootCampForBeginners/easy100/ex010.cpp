#include <bits/stdc++.h>

using namespace std;

#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int N;
  vector<int> a(100);
  cin >> N;
  rep(i, 0, N)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  // rep(i, 0, N)
  // {
  //   cout << a[i];
  // }

  int aSum = 0, bSum = 0;
  rep(i, 0, N)
  {
    if (i % 2 == 0)
    {
      aSum += a[i];
    }
    else
    {
      bSum += a[i];
    }
  }
  // cout << aSum << endl;
  // cout << bSum << endl;
  cout << aSum - bSum << endl;
  return 0;
}
