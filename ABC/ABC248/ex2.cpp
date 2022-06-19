#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  long ans = A;
  int count = 0;
  while (ans < B)
  {
    ans *= K;
    count++;
  }

  cout << count << endl;
  return 0;
}
