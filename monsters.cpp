// // Rishikesh Chaudhari
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// bool custom_cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
//     // Comparing second elements in descending order
//     // If second elements are equal, compare first elements in ascending order
//     if (a.second != b.second) {
//         return a.second > b.second; // Sort by second element in descending order
//     }
//     return a.first < b.first; // Sort by first element in ascending order
// }
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, k;
//         cin >> n >> k;
//         // cout<<n<<" "<<k<<" ";
//         vector<pair<ll, ll>> arr;
//         vector<pair<ll, ll>> arr2;
//         // ll j = 0, k = 0;
//         for (ll i = 0; i < n; i++)
//         {
//             ll x;
//             cin >> x;
//             // arr[i].first = i+1;
//             if (x % k == 0)
//             {
//                 arr.push_back(std::make_pair(i+1,k));
//                 // arr2.push_back(i + 1);
//             }
//             else
//                 arr.push_back(std::make_pair(i + 1, x % k));
//         }
//         // sort(arr2.begin(), arr2.end(), [&](pair<ll, ll> x, pair<ll, ll> y)
//         //      { return x.first < y.first; });
//         // for (auto i:arr2)
//         // {
//         //     cout << i.first << " ";
//         // }
//         // sort(arr.begin(), arr.end(), [&](pair<ll, ll> x, pair<ll, ll> y)
//         //      { return x.second > y.second; });
//         // sort(arr.begin(),arr.end(),greater<int>());
//         // for (ll i=0; i<arr.size(); i++)
//         // {
//         //     cout<<arr[i].second<<" ";
//         // }
//         sort(arr.begin(),arr.end(),custom_cmp);
//         for (ll i = 0; i < arr.size(); i++)
//         {
//             cout << arr[i].first << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// } /*
//  1 1
//  1
//  1 2
//  1
//  1 3
//  1
//  1 4
//  1
//  1 1
//  2
//  1 2
//  2
//  1 3
//  2
//  1 4
//  2
//  1 1
//  3
//  1 2
//  3
//  1 3
//  3
//  1 4
//  3
//  1 1
//  4
//  1 2
//  4
//  1 3
//  4
//  1 4
//  4
//  2 1
//  1 1
//  2 2
//  1 1
//  2 3
//  1 1
//  2 4
//  1 1
//  2 1
//  1 2
//  2 2
//  1 2
//  2 3
//  1 2
//  2 4
//  1 2
//  2 1
//  1 3
//  2 2
//  1 3
//  2 3
//  1 3
//  2 4
//  1 3
//  2 1
//  1 4
//  2 2
//  1 4
//  2 3
//  1 4
//  2 4
//  1 4
//  2 1
//  2 1
//  2 2
//  2 1
//  2 3
//  2 1
//  2 4
//  2 1
//  2 1
//  2 2
//  2 2
//  2 2
//  2 3
//  2 2
//  2 4
//  2 2
//  2 1
//  2 3
//  2 2
//  2 3
//  2 3
//  2 3
//  2 4
//  2 3
//  2 1
//  2 4
//  2 2
//  2 4
//  2 3
//  2 4
//  2 4
//  2 4
//  2 1
//  3 1
//  2 2
//  3 1
//  2 3
//  3 1
//  2 4
//  3 1
//  2 1
//  3 2
//  2 2

//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  2 1
//  2 1
//  2 1
//  1 2
//  1 2
//  2 1
//  2 1
//  1 2
//  2 1
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  2 1
//  2 1
//  1 2
//  1 2
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  2 1
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  2 1
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2
//  1 2 3
//  1 2 3
//  1 2 3
//  1 2 3
//  */

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