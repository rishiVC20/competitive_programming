// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//         if (n==2){
//             cout<<"YES"<<endl;
//             cout<<9<<" "<<5<<endl;
//         }
//         else if (n==3)
//             cout<<"NO"<<endl;
//         else{
//             // cout<<"NO"<<endl;
//             cout<<"YES"<<endl;
//             if (n%2 ==0){
//                 for (ll i=0; i<n; i++){
//                     if (i%2==0)
//                         cout<<1<<" ";
//                     else    
//                         cout<<-1<<" ";    
//                 }
//             }
//             else if (n%2 != 0){
//                 for (ll i=0; i<n; i++){
//                     if(i%2==0)
//                         cout<<(n/2)-1<<" ";
//                     else
//                         cout<<-(n/2)<<" ";    
//                 }
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }

// // https://codeforces.com/problemset/problem/1779/B

if((year/4==0 && year/100==0)&&year/400==0)
    cout<<"Leap year."<<endl;
else    
    cout<<"Not Leap year"<<endl;    

    return "Leap year."
    return "Not leap year."