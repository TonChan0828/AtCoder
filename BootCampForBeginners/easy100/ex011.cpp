#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int N;
  cin >> N;
  int maxCount = 0;
  int value = 1;
  rep(i, N)
  {
    int count = 0;
    int target = (i + 1);
    while ((target % 2) == 0)
    {
      target /= 2;
      count++;
    }
    if (maxCount < count)
    {
      maxCount = count;
      value = (i + 1);
    }
  }
  cout << value << endl;
  return 0;
}
