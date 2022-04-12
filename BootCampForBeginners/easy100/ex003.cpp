#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;

  int bCount = 0;
  int winner = 0;

  for (int i = 0; i < N; i++)
  {
    if (winner < A + B)
    {
      char c = S.at(i);
      if (c == 'a')
      {
        cout << "Yes" << endl;
        winner++;
      }
      else if (c == 'b' && (bCount < B))
      {
        cout << "Yes" << endl;
        winner++;
        bCount++;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else
    {
      cout << "No" << endl;
    }
  }

  return 0;
}
