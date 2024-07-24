// // // // Rishikesh Chaudhari
// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // #define ll long long
// // // int main() {
// // //     ll t;
// // //     cin>>t;
// // //     while (t--)
// // //     {

// // //     }
// // //     return 0;
// // // }

// // #include <bits/stdc++.h>
// // // #include <vector>
// // // #include <unordered_map>
// // using namespace std;

// // pair<vector<int>, vector<int>> findArrays(int n, int k, vector<int> &a, vector<int> &b)
// // {
// //     vector<int> l, r;
// //     unordered_map<int, int> freq;

// //     int X = 0, Y = 0;
// //     for (int num : a)
// //         X ^= num;
// //     for (int num : b)
// //         Y ^= num;

// //     int Z = X ^ Y; // Target XOR sum

// //     int currXor = 0;
// //     for (int i = 0; i < n; ++i)
// //     {
// //         currXor ^= a[i];
// //         if (i >= 2 * k)
// //             currXor ^= a[i - 2 * k];
// //         if (i >= 2 * k - 1 && freq[currXor ^ Z] < 2 * k)
// //         {
// //             for (int j = i - 2 * k + 1; j <= i; ++j)
// //             {
// //                 l.push_back(a[j]);
// //             }
// //             for (int num : b)
// //             {
// //                 if (freq[num] < 2 * k && find(l.begin(), l.end(), num ^ Z) == l.end())
// //                 {
// //                     r.push_back(num);
// //                     freq[num]++;
// //                     if (r.size() == 2 * k)
// //                         break;
// //                 }
// //             }
// //             if (l.size() == 2 * k && r.size() == 2 * k)
// //                 break;
// //         }
// //     }

// //     return {l, r};
// // }

// // int main()
// // {
// //     int n = 6;
// //     int k = 2;
// //     vector<int> a = {5,1,3,3,5,1};
// //     vector<int> b = {2,6,4,6,4,2};

// //     pair<vector<int>, vector<int>> result = findArrays(n, k, a, b);

// //     // cout << "Array l: ";
// //     for (int num : result.first)
// //         cout << num << " ";
// //     cout << endl;

// //     // cout << "Array r: ";
// //     for (int num : result.second)
// //         cout << num << " ";
// //     cout << endl;

// //     return 0;
// // }





// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// pair<vector<ll>,vector<ll>>solve(vector<ll>&a, vector<ll>&b, ll n, ll k)
// {
//     vector<ll>l,r;
//     unordered_map<ll,ll>freq;
//     ll sum1 = 0,sum2 = 0;
//     for (auto i:a)
//         sum1 ^= i;
//     for (auto i:b)
//         sum2 ^= i;
//     ll sum3 = sum1^sum2;
//     ll sum = 0;
//     for (ll i=0; i<n; i++)
//     {
//         sum ^= a[i];
//         if (i>=2*k )
//             sum ^=a[i-2*k];
//         if (i>=2*k-1 && freq[sum^sum3]<2*k)
//         {
//             for (ll j=i-2*k+1; j<=i; j++)
//             {
//                 l.push_back(a[j]);
//             }
//             for (ll num:b)
//             {
//                 if (freq[num]<2*k && find(l.begin(),l.end(),num^sum3)==l.end())
//                 {
//                     r.push_back(num);
//                     freq[num]++;
//                     if (r.size() == 2*k)
//                         break;
//                 }
//             }
//             if (l.size()==2*k && r.size()==2*k)
//                 break;
//         }    
        
//     }
//     // for (ll num:l)
//     //     cout<<num<<" ";
//     // for (ll num:r)
//     //     cout<<num<<" ";    
//     return {l,r};
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         // cout<<n<<" "<<k<<endl;
//         vector<ll>a,b;
//         for (ll i=0; i<2*n; i++)
//         {
//             ll x; cin>>x;
//             if (i<n)
//                 a.push_back(x);
//             else
//                 b.push_back(x);    
//         }
//         // for (ll i=0; i<a.size(); i++)
//         //     cout<<a[i]<<" ";
//         // for (ll i=0; i<b.size(); i++)
//         //     cout<<b[i]<<" ";    
//         pair<vector<ll>,vector<ll>>ans = solve(a,b,n,k);


//         for (ll num:ans.first)
//             cout<<num<<" ";
//         cout<<endl;

//         for (ll num:ans.second)
//             cout<<num<<" ";
//         cout<<endl;         
//     }
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
        vector<ll>a,b;
        unordered_map<ll,ll>v1,v2;
        for (ll i=0; i<2*n; i++)
        {
            ll x;
            cin>>x;
            if (i<n){
                a.push_back(x);
                v1[x]++;
            }
            else{
                b.push_back(x);  
                v2[x]++;
            }  
        }
        vector<ll>l,r;
        ll h = k*2;
        ll count = 0;
        for (auto i:v1)
        {
            if (h>0 && i.second==2)
            {
                l.push_back(i.first);
                l.push_back(i.first);
                h -= 2;
                count++;
            }
        }
        for (auto i:v2)
        {
            if (count>0 && i.second==2)
            {
                r.push_back(i.first);
                r.push_back(i.first);
                count--;
            }
        }
        for (auto i:v1)
        {
            if (h>0 && i.second==1)
            {
                l.push_back(i.first);
                r.push_back(i.first);
                h--;
            }
        }
        for (auto num:l)
            cout<<num<<" ";
        cout<<endl;

        for (auto num:r)
            cout<<num<<" ";
        cout<<endl;



    }
    return 0;
}