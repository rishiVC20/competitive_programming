#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll partition(vector<pair<double, double>> &arr, ll low, ll high)
{
    double p = arr[high].first;
    double i = low - 1;
    for (double j = low; j < high; j++)
    {
        if (arr[j].first <= p)
        {
            i++;
            swap(arr[i], arr[j]);
            // i++;
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<pair<double, double>> &arr, ll low, ll high)
{
    if (low < high)
    {
        ll k = partition(arr, low, high);

        quickSort(arr, low, k - 1);
        quickSort(arr, k + 1, high);
    }
}
int main()
{
    ll n;
    cout << "Enter number of items: ";
    cin >> n;
    ll cap;
    cout << "Enter capacity of bag: ";
    cin >> cap;
    vector<double> profit(n);
    vector<double> weight(n);
    cout << "Enter " << n << " number of profits: ";
    for (ll i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    cout << "Enter " << n << " number of weights: ";
    for (ll i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<pair<double, double>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        arr[i].first = profit[i] / weight[i];
        arr[i].second = i;
    }

    quickSort(arr, 0, n - 1);

    // for (auto i:arr){
    //     cout<<i.first<<' '<<i.second;
    //     cout<<endl;
    // }

    double sum = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        int p = arr[i].second;
        if (weight[p] <= cap)
        {
            sum += profit[p];
            cap -= weight[p];
        }
        else if (cap != 0)
        {
            sum += arr[i].first * cap;
            break;
        }
    }

    cout << "max profit: " << sum << endl;
}