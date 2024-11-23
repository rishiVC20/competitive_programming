// #include <bits/stdc++.h>
// using namespace std;

// bool findSubsetSum(vector<int> &nums, int index, int k, int n, vector<int> &ans)
// {

//     if (index >= n)
//     {
//         if (k == 0)
//         {

//             cout << "\n\nfound the solution !!\n\n";
//             return true;
//         }
//         return false;
//     }

//     ans.push_back(nums[index]);

//     cout << "\nAdded the element : " << nums[index] << "\n\n";
//     // take

//     cout << "\n checking that the remaining element : " << k - nums[index] << " can be formed from the list : \n\n";
//     if (findSubsetSum(nums, index + 1, k - nums[index], n, ans))
//     {

//         return true;
//     }

//     cout << "\n\nRemoving the element : " << nums[index] << " from the list !!\n\n";
//     // not take
//     ans.pop_back();

//     cout << "\n\nChecking if the required number " << k << " can be formed from the list  !!\n\n";
//     if (findSubsetSum(nums, index + 1, k, n, ans))
//     {
//         return true;
//     }

//     return false;
// }

// void findSubset(vector<int> &nums, int k)
// {

//     vector<int> ans;
//     int n = nums.size();
//     int index = 0;
//     if (findSubsetSum(nums, index, k, n, ans))
//     {
//         cout << "\nThe required subset is : \n";
//         for (int ele : ans)
//         {
//             cout << ele << " ";
//         }
//         cout << endl;
//         return;
//     }
//     else
//     {
//         cout << "The subset does not exist !!" << endl;
//         return;
//     }
// }

// int main()
// {

//     vector<int> nums = {1, 5, 4, 2, 3, 6, 8};
//     findSubset(nums, 10);
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;
// Function to print a subset
void printSubset(const vector<int> &subset)
{
    cout << "{ ";
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << "}" << endl;
}
// Recursive function to find subsets that sum to M
void subsetSum(const vector<int> &w, vector<int> &subset, int index, int currentSum, int M)
{
    // Base case: If the current sum is equal to M, print the subset
    if (currentSum == M)
    {
        printSubset(subset);
        return;
    }

    // If the sum exceeds M or we have reached the end of the array, return
    if (currentSum > M || index == w.size())
    {
        return;
    }

    // Include the current element and proceed
    subset.push_back(w[index]);
    subsetSum(w, subset, index + 1, currentSum + w[index], M);

    // Exclude the current element and proceed
    subset.pop_back();
    subsetSum(w, subset, index + 1, currentSum, M);
}

void findSubsetsWithSumM(const vector<int> &w, int M)
{
    vector<int> subset;
    cout << "Subsets of sum " << M << ":\n";
    subsetSum(w, subset, 0, 0, M);
    cout << endl;
}

int main()
{
    int M = 35;

    vector<int> w1 = {5, 7, 10, 12, 15, 18, 20};
    vector<int> w2 = {20, 18, 15, 12, 10, 7, 5};
    vector<int> w3 = {15, 7, 20, 5, 18, 10, 12};

    cout << "For set w1:\n";
    findSubsetsWithSumM(w1, M);

    cout << "For set w2:\n";
    findSubsetsWithSumM(w2, M);

    cout << "For set w3:\n";
    findSubsetsWithSumM(w3, M);

    return 0;
}
