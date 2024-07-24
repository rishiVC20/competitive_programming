// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // #define pb push_back 
// // #define onebit(x) __builtin_popcountll(x)
// // #define vi vector<ll> 

// // const ll mod = 1e9+7;

// // ll mul (ll a, ll b, ll m=mod)
// // {
// //     a = a % m;
// //     b = b % m;
// //     return (((a * b) % m) + m) % m;
// // }
// // ll LCM(ll a, ll b)
// // {
    
// //     a = (a*b)/(__gcd(a,b));
// //     return a;
// // }
// // ll power(ll base, ll exponent)
// // {
// //     if (exponent < 0)
// //     {
// //         return 0;
// //     }
// //     ll ans = 1;
// //     while (exponent)
// //     {
// //         if (exponent%2==0)
// //         {
// //             base = (base*base) % mod;
// //             exponent = exponent/2;
// //         }
// //         else
// //         {
// //             ans = (ans*base) % mod;
// //             exponent--;
// //         }
// //     }
// //     return ans;
// // }


// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll x,y,z,k;
// //         cin>>x>>y>>z>>k;
// //         ll sq = x*y*z;
// //         if (k > sq){
// //             cout<<0<<endl;
// //             continue;
// //         }       


// //     }
// //     return 0;
// // }


// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <cmath>

// // Function to find all factors of a given number
// std::vector<int> find_factors(int n) {
//     std::vector<int> factors;
//     for (int i = 1; i <= std::sqrt(n); ++i) {
//         if (n % i == 0) {
//             factors.push_back(i);
//             if (i != n / i) {
//                 factors.push_back(n / i);
//             }
//         }
//     }
//     return factors;
// }

// // Function to generate all valid dimensions (a, b, c) such that a * b * c = k
// std::set<std::tuple<int, int, int>> generate_dimensions(int k) {
//     std::vector<int> factors = find_factors(k);
//     std::set<std::tuple<int, int, int>> dimensions;

//     for (int i = 0; i < factors.size(); ++i) {
//         for (int j = 0; j < factors.size(); ++j) {
//             for (int l = 0; l < factors.size(); ++l) {
//                 if (factors[i] * factors[j] * factors[l] == k) {
//                     std::vector<int> temp = {factors[i], factors[j], factors[l]};
//                     std::sort(temp.begin(), temp.end());
//                     dimensions.insert(std::make_tuple(temp[0], temp[1], temp[2]));
//                 }
//             }
//         }
//     }
//     return dimensions;
// }

// // Function to find the maximum number of placements
// int max_placements(int x, int y, int z, int k) {
//     std::set<std::tuple<int, int, int>> dimensions = generate_dimensions(k);
//     int max_place = 0;

//     for (const auto& dim : dimensions) {
//         int a, b, c;
//         std::tie(a, b, c) = dim;

//         if (a <= x && b <= y && c <= z) {
//             int placements = (x - a + 1) * (y - b + 1) * (z - c + 1);
//             max_place = std::max(max_place, placements);
//         }
//     }
//     return max_place;
// }

// int main() {
//     int x, y, z, k;
//     std::cout << "Enter the dimensions of the box B (x, y, z): ";
//     std::cin >> x >> y >> z;
//     std::cout << "Enter the volume of the secret box S (k): ";
//     std::cin >> k;

//     int result = max_placements(x, y, z, k);
//     std::cout << "The maximum number of distinct locations is: " << result << std::endl;

//     return 0;
// }



// #include <iostream>
// #include <vector>
// #include <set>
// #include <cmath>
// #include <algorithm>

// // Function to find all factors of a given number
// std::vector<int> find_factors(int n) {
//     std::vector<int> factors;
//     for (int i = 1; i <= std::sqrt(n); ++i) {
//         if (n % i == 0) {
//             factors.push_back(i);
//             if (i != n / i) {
//                 factors.push_back(n / i);
//             }
//         }
//     }
//     return factors;
// }

// // Function to find the maximum number of placements
// int max_placements(int x, int y, int z, int k) {
//     std::vector<int> factors = find_factors(k);
//     int max_place = 0;

//     for (int i = 0; i < factors.size(); ++i) {
//         for (int j = 0; j < factors.size(); ++j) {
//             if (k % (factors[i] * factors[j]) == 0) {
//                 int a = factors[i];
//                 int b = factors[j];
//                 int c = k / (a * b);
                
//                 if (a <= x && b <= y && c <= z) {
//                     int placements = (x - a + 1) * (y - b + 1) * (z - c + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//                 // Check other permutations of (a, b, c)
//                 if (a <= x && c <= y && b <= z) {
//                     int placements = (x - a + 1) * (y - c + 1) * (z - b + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//                 if (b <= x && a <= y && c <= z) {
//                     int placements = (x - b + 1) * (y - a + 1) * (z - c + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//                 if (b <= x && c <= y && a <= z) {
//                     int placements = (x - b + 1) * (y - c + 1) * (z - a + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//                 if (c <= x && a <= y && b <= z) {
//                     int placements = (x - c + 1) * (y - a + 1) * (z - b + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//                 if (c <= x && b <= y && a <= z) {
//                     int placements = (x - c + 1) * (y - b + 1) * (z - a + 1);
//                     max_place = std::max(max_place, placements);
//                 }
//             }
//         }
//     }
//     return max_place;
// }

// int main() {
//     int x, y, z, k;
//     // std::cout << "Enter the dimensions of the box B (x, y, z): ";
//     std::cin >> x >> y >> z;
//     // std::cout << "Enter the volume of the secret box S (k): ";
//     std::cin >> k;

//     int result = max_placements(x, y, z, k);
//     // std::cout << "The maximum number of distinct locations is: " << result << std::endl;
//     cout<<result<<endl;
//     return 0;
// }


// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}

vi fact(ll k)
{
    vi dd;
    for (ll i=1; i<=sqrt(k); i++)
    {
        if (k%i==0){
            dd.pb(i);
            if (i!=k/i)
                dd.pb(k/i);
        }
    }

    return dd;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll x,y,z,k;
        cin>>x>>y>>z>>k;
        vi dd = fact(k);    

        ll maxi = 0;

        for (ll i=0; i<dd.size(); i++)
        {   
            for (ll j=0; j<dd.size(); j++)
            {
                if (k%(dd[i]*dd[j])==0){
                    ll p1 = dd[i];
                    ll p2 = dd[j];
                    ll p3 = k/(dd[i]*dd[j]);

                    if (p1<=x && p2<=y &&p3<=z){
                        ll q = (x - p1 + 1) * (y - p2 + 1) * (z - p3 + 1);
                        maxi = max(maxi,q);
                    }    
                    if (p1<=x && p3<=y && p2<=z){
                        ll q = (x - p1 + 1) * (y - p3 + 1) * (z - p2 + 1);
                        maxi = max(maxi,q);
                    }
                    if (p2<=x && p1<=y && p3<=z){
                        ll q = (x - p2 + 1) * (y - p1 + 1) * (z - p3 + 1);
                        maxi = max(maxi,q);
                    }
                    if (p2<=x && p3<=y && p1<=z){
                        ll q = (x - p2 + 1) * (y - p3 + 1) * (z - p1 + 1);
                        maxi = max(maxi,q);
                    }
                    if (p3<=x && p1<=y && p2<=z){
                        ll q = (x - p3 + 1) * (y - p1 + 1) * (z - p2 + 1);
                        maxi = max(maxi,q);
                    }
                    if (p3<=x && p2<=y && p1<=z){
                        ll q = (x - p3 + 1) * (y - p2 + 1) * (z - p1 + 1);
                        maxi = max(maxi,q);
                    }
                }
            }
        }

        cout<<maxi<<endl;
    }
    return 0;
}