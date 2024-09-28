#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n;

  cout << "Enter value of n for nxn matrix" << endl;

  cin >> n;

  vector<int> digits(n);
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++)
  {
    digits[i] = i + 1;
  }

  int flag = 0;
  while (next_permutation(digits.begin(), digits.end()))
  {
    flag = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if ((digits[i] - i == digits[j] - j) || digits[i] + i == digits[j] + j)
        {
          flag = 1;
        }
      }
      if (flag == 0)
      {
        ans.push_back(digits);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}