#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

int main()
{
  int A, B, C, D, E, F, X;
  cin >> A >> B >> C >> D >> E >> F >> X;
  string ans = "Draw";
  int Taka = 0, Aoki = 0;
  int tmp = 0, alfa = 0;
  tmp = X % (A + C);
  if (tmp < A)
  {
    alfa = tmp;
  }
  else
  {
    alfa = A;
  }
  Taka = (B * A * (X / (A + C))) + (alfa * B);

  tmp = 0;
  alfa = 0;
  tmp = X % (D + F);
  if (tmp < D)
  {
    alfa = tmp;
  }
  else
  {
    alfa = D;
  }

  Aoki = (E * D * (X / (D + F))) + (alfa * E);

  // cout << Taka << " " << Aoki << endl;

  if (Taka > Aoki)
  {
    ans = "Takahashi";
  }
  else if (Taka < Aoki)
  {
    ans = "Aoki";
  }

  cout << ans << endl;
  return 0;
}
