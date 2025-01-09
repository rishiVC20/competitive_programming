#include <bits/stdc++.h>
using namespace std;

bool ispr(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool ispalin(int num)
{
    int original = num, reversed = 0;
    while (num > 0)
    {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}

void generate(int sequenceSize)
{
    int count = 0, num = 2;
    while (count < sequenceSize)
    {
        if (ispr(num) && ispalin(num))
        {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;

    generate(size);

    return 0;
}