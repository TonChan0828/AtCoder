#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string a, b;
  cin >> a >> b;
  int num = stoi(a + b);

  // cout << num;
  int ans = 0;
  for (int i = 1; i <= 317; i++)
  {
    if (i * i == num)
    {
      ans++;
      break;
    }
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
