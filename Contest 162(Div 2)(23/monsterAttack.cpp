// // // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// // #define ll long long 
// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll n,k;
// //         cin>>n>>k;

// //         vector<ll>health(n);
// //         vector<ll>storehealth;
// //         vector<ll>storepos;
// //         vector<ll>store;
// //         ll sum = 0;
// //         ll cnt = 0;
// //         bool flag = true;
// //         for (ll i=0; i<n; i++){
// //             cin>>health[i];
// //             if (k < health[i])
// //                 flag = false;
// //             if (k <= health[i]){
// //                 sum += health[i];
// //                 cnt++;
// //             }    
// //             if (k > health[i]){
// //                 storehealth.push_back(health[i]);
// //                 storepos.push_back(i);
// //             }
// //         }
// //         ll p = 0;
// //         vector<ll>pos(n);
// //         for (ll i=0; i<n; i++){
// //             cin>>pos[i];
// //             if (storepos[p] == i){
// //                 store.push_back(abs(pos[i]));
// //                 p++;
// //             }
// //         }
        
// //         if (flag)
// //             cout<<"YES"<<endl;
// //         else
// //         {
// //             ll p =k*cnt;
// //             if (p < sum)
// //                 cout<<"NO"<<endl;
            
// //             else
// //             {   
// //                 p = p - sum;
// //                 bool result = false;
// //                 for (ll i=0; i<storehealth.size(); i++){
// //                     ll m = store[i] - k;
// //                     if (m < store[i]){
// //                         cout<<"NO"<<endl;
// //                         break;
// //                     }
// //                     else{
// //                         if (p+k*m > store[i])
// //                             cout<<"YES"<<endl;
// //                         else
// //                             cout<<"NO"<<endl;    
// //                     }
// //                 }
// //             }    
// //         }
            

// //     }
// //     return 0;
// // // }
// // #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // using namespace std;

// string canSurvive(int t, vector<vector<int>>& test_cases) {
//     vector<string> results;

//     for (int i = 0; i < t; ++i) {
//         int n = test_cases[i][0];
//         int k = test_cases[i][1];
//         vector<int> health(n);
//         vector<int> positions(n);

//         for (int j = 0; j < n; ++j) {
//             health[j] = test_cases[i][2 + j];
//         }

//         for (int j = 0; j < n; ++j) {
//             positions[j] = test_cases[i][2 + n + j];
//         }

//         int closest_monster = INT_MAX;
//         int max_health = *max_element(health.begin(), health.end());

//         for (int j = 0; j < n; ++j) {
//             closest_monster = min(closest_monster, abs(positions[j]));
//         }

//         int bullets_needed = max(closest_monster - 1, 0);

//         if (bullets_needed > k) {
//             results.push_back("NO");
//         } else {
//             if (max_health <= k - bullets_needed) {
//                 results.push_back("YES");
//             } else {
//                 results.push_back("NO");
//             }
//         }
//     }

//     string output = "";
//     for (const auto& result : results) {
//         output += result + "\n";
//     }
//     return output;
// }

// int main() {
//     int t;
//     cin >> t;

//     vector<vector<int>> test_cases(t, vector<int>(2));

//     for (int i = 0; i < t; ++i) {
//         int n, k;
//         cin >> n >> k;
//         test_cases[i][0] = n;
//         test_cases[i][1] = k;

//         test_cases[i].resize(2 + 2 * n);
//         for (int j = 0; j < 2 * n; ++j) {
//             cin >> test_cases[i][2 + j];
//         }
//     }

//     cout << canSurvive(t, test_cases);

//     return 0;
// }


// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        vector<ll>b(n+1,0);
        for (ll i=0; i<n; i++){
            int x;
            cin>>x;
            b[abs(x)] += arr[i];
        }    

        bool f = true;
        ll rem = 0;
        for (ll i=1; i<=n; i++){
            rem += k;
            if (rem < b[i]){
                f = false;
            }
            else
                rem -= b[i];    
        }
        if (f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        
    }
    return 0;
}