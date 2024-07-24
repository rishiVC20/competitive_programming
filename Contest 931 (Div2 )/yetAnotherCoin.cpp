// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll n;
// //         cin>>n;
// //         ll arr[5] = {15, 10, 6, 3, 1};
// //         ll count = 0;
// //         ll p=0;
// //         for (ll j=0; j<5; j++)
// //         {
// //             if (n>=arr[j]){
// //                 p = j;
// //                 break;
// //             }
// //         }
// //         ll i=p;
// //         while (n >= arr[i])
// //         {
// //             n -= arr[i];
// //             count++;
// //             if (n < arr[i])
// //                 i++;
// //         }
// //         cout<<count<<endl;
// //     }
// //     return 0;
// // }

// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll n;
// //         cin>>n;
// //         ll ans = 0;
// //         if (n%15 == 0){
// //             cout<<n/15<<endl;
// //             // ans += min(ans,n/15)
// //             continue;
// //         }
// //         if (n%10 == 0 && n/15 < 2){
// //             cout<<n/10<<endl;
// //             continue;
// //         }
// //         if ((n%6 == 0 && n/10 < 2) && n<15){
// //             cout<<n/6<<endl;
// //             continue;
// //         }
// //         if ((n%3 == 0 && n/6 < 2) && n<6){
// //             cout<<n/3<<endl;
// //             continue;
// //         }
// //         // if (n%1 == 0){
// //         //     cout<<n/1<<endl;
// //         //     continue;
// //         // }
// //         ll p1 = n/15;
// //         n -= p1*15;
// //         // cout<<p1<<" ";
// //         if (n%15 == 0){
// //             cout<<p1+n/15<<endl;
// //             continue;
// //         }
// //         if (n%10 == 0 && n/15 < 2){
// //             cout<<p1+n/10<<endl;
// //             continue;
// //         }
// //         if ((n%6 == 0 && n/10 < 2) && n<15){
// //             cout<<p1+n/6<<endl;
// //             continue;
// //         }
// //         if ((n%3 == 0 && n/6 < 2) && n<6){
// //             cout<<p1+n/3<<endl;
// //             continue;
// //         }
// //         ll p2 = n/10;
// //         n -= p2*10;
// //         // cout<<p2<<" ";
// //         if (n%15 == 0){
// //             cout<<p1+p2+n/15<<endl;
// //             continue;
// //         }
// //         if (n%10 == 0 && n/15 < 2){
// //             cout<<p1+p2+n/10<<endl;
// //             continue;
// //         }
// //         if ((n%6 == 0 && n/10 < 2) && n<15){
// //             cout<<p1+p2+n/6<<endl;
// //             continue;
// //         }
// //         if ((n%3 == 0 && n/6 < 2) && n<6){
// //             cout<<p1+p2+n/3<<endl;
// //             continue;
// //         }
// //         ll p3 = n/6;
// //         n -= p3*6;
// //         // cout<<p3<<" ";
// //         if (n%15 == 0){
// //             cout<<p1+p2+p3+n/15<<endl;
// //             continue;
// //         }
// //         if (n%10 == 0 && n/15 < 2){
// //             cout<<p1+p2+p3+n/10<<endl;
// //             continue;
// //         }
// //         if ((n%6 == 0 && n/10 < 2) && n<15){
// //             cout<<p1+p2+p3+n/6<<endl;
// //             continue;
// //         }
// //         if ((n%3 == 0 && n/6 < 2) && n<6){
// //             cout<<p1+p2+p3+n/3<<endl;
// //             continue;
// //         }
// //         ll p4 = n/3;
// //         n -= p4*3;
// //         // cout<<p4<<" ";
// //         if (n%15 == 0){
// //             cout<<p1+p2+p3+p4+n/15<<endl;
// //             continue;
// //         }
// //         if (n%10 == 0 && n/15 < 2){
// //             cout<<p1+p2+p3+p4+n/10<<endl;
// //             continue;
// //         }
// //         if ((n%6 == 0 && n/10 < 2) && n<15){
// //             cout<<p1+p2+p3+p4+n/6<<endl;
// //             continue;
// //         }
// //         if ((n%3 == 0 && n/6 < 2) && n<6){
// //             cout<<p1+p2+p3+p4+n/3<<endl;
// //             continue;
// //         }
// //         ll p5 = n/1;
// //         n -= p5*1;
// //         // cout<<p5<<" ";
// //         cout<<(p1+p2+p3+p4+p5)<<endl;
// //     }
// //     return 0;
// // }

// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll n;
// //         cin>>n;
// //         ll arr[4] = {25,16,9,4};
// //         // ll sum = 0;
// //         ll p1 = n/25;
// //         n -= 25*p1;
// //         ll p2 = n/16;
// //         n -= 16*p2;
// //         ll p3 = n/9;
// //         n -= 9*p3;
// //         ll p4 = n/4;
// //         n -= p4*4;
// //         cout<<(p1+p2+p3+p4)+n<<endl;
// //     }
// //     return 0;
// // }

// // Rishikesh Chaudhari
// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// ll solveRec(vector<ll> &coins, ll n)
// {
//     if (n == 0)
//         return 0;
//     if (n < 0)
//         return INT_MAX;

//     ll mini = INT_MAX;
//     for (ll i = 0; i < coins.size(); i++)
//     {
//         ll ans = solveRec(coins, n - coins[i]);
//         if (ans != INT_MAX)
//             mini = min(mini, 1 + ans);
//     }
//     return mini;
// }

// ll solveMem(vector<ll> &coins, ll n, vector<ll> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (n < 0)
//         return INT_MAX;

//     if (dp[n] != -1)
//         return dp[n];

//     ll mini = INT_MAX;
//     for (ll i = 0; i < coins.size(); i++)
//     {
//         ll ans = solveRec(coins, n - coins[i]);
//         if (ans != INT_MAX)
//             mini = min(mini, 1 + ans);
//     }
//     dp[n] = mini;
//     return dp[n];
// }

// ll solveTab(vector<ll>&num, int x)
// {
//     vector<ll>dp(x+1,INT_MAX);
//     dp[0]=0;
//     for (ll i=1; i<=x; i++)
//     {
//         for (ll j=0; j<num.size(); j++)
//         {
//             if (i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
//                 dp[i] = min(dp[i],1+dp[i-num[j]]);
//         }
//     }
//     if (dp[x] == INT_MAX)
//         return -1;

//     return dp[x];    
// }
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vector<ll> coins = {1, 3, 6, 10, 16};
//     //     // ll ans = solveRec(coins, n);
//     //     // cout<<ans<<endl;

//     //     vector<ll> dp(n + 1, -1);
//     //     ll ans = solveMem(coins, n, dp);
//     //     cout << ans << endl;

//         cout<<solveTab(coins, n)<<endl;
//     }
//     return 0;
// }

// /*
// 1
// 2
// 1
// 3
// 2
// 2
// 2
// 3
// 2
// 3
// 2
// 2
// 8
// 26862090

// */




// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll ans = INT_MAX;
        for (ll ones = 0; ones<=2; ones++)
        {
            for (ll threes=0; threes<=1; threes++)
            {
                for (ll sixs=0; sixs<=3; sixs++)
                {
                    for (ll tens=0; tens<=2; tens++)
                    {
                        ll brute = 1*ones+3*threes+6*sixs+10*tens;
                        if (brute<=n && (n-brute)%15==0)
                            ans = min(ans,ones+threes+sixs+tens+(n-brute)/15);
                    }
                }
            }
        }        
        cout<<ans<<endl;
    }
    return 0;
}


/*
int main() {
	ll a=123 ;
	cin >> a ;	
	while(a--){
		ll n;
		cin>>n;
		int i = 1;
        ll div = 1;
        vector<int> arr = {0,1,2,1,2,3,1,2,3,2,1,2,3,2,3,1};
        arr[12] = 2;
        
        if(n < 15){
            cout<<arr[n]<<endl;
        }
        else{
            arr[5] = 1;
            arr[8] = 2;
            cout<<n/15+arr[n%15]<<endl;
            arr[5] = 3;
            arr[8] = 3;
        }
       
	}
	
	return 0;
 }

//  https://codeforces.com/contest/1934/problem/B
*/