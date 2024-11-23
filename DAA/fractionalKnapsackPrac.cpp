#include <bits/stdc++.h>
using namespace std;
struct item
{
    /* data */
    int wt;
    int pt;
    double rt;
};

// int partition(struct item arr[], int low, int high)
// {
//     int pivot = arr[low].rt;
//     int i = low + 1, j = high;

//     while (i <= j)
//     {

//         while (i <= j && arr[i].rt <= pivot)
//             i++;

//         while (i <= j && arr[j].rt >= pivot)
//             j--;
//         swap(arr[i], arr[j]);
//     }
//     swap(arr[j], arr[low]);

//     return j;
// }

int partition(struct item arr[], int low, int high){
    double p = arr[high].rt;
    double i = low - 1;
    for (double j = low; j < high; j++)
    {
        if (arr[j].rt <= p)
        {
            i++;
            swap(arr[i], arr[j]);
            // i++;
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(struct item arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter number of items :";
    cin >> n;
    int twt;
    cout << "Enter total weight :";
    cin >> twt;
    struct item v[n];
    cout << "Enter " << n << " Profits :";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i].pt = x;
    }
    cout << "Enter " << n << " Weights :";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i].wt = x;

        double p = v[i].pt / v[i].rt;
        v[i].rt = p;
    }

    quickSort(v, 0, n - 1);

    double total = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i].wt <= twt)
        {
            total += v[i].pt;
            twt -= v[i].wt;
        }
        else if (twt > 0)
        {
            double k = (v[i].pt / v[i].rt) * twt;
            total += k;
            break;
        }
        else
        {
            break;
        }
    }

    cout << "Total profit is " << total << endl;
}