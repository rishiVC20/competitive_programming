// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     int count = 0;
//     while (n){
//         if (n & 1)
//             count++;
//         n = n>>1;    
//     }   
//     cout<<count;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int t;
// 	cin>>t;
// 	while (t--)
// 	{
// 	    int x,n;
// 	    cin>>x>>n;
// 	    string s;
// 	    cin>>s;
// 	    int count = 0;
// 	    int flag=0;
// 	    for (int i=0; i<x; i++)
// 	    {
// 	        if(s[i] == '1')
// 	            flag = n;
// 	        if(s[i] == '0')
// 	            flag--;
// 	    }
// 	   if (flag>=0)
// 	    cout<<"YES"<<endl;
// 	   else
// 	    cout<<"NO"<<endl;
	    
// 	}

// }


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int t;
// 	cin>>t;
// 	while (t--)
// 	{
// 	    int x,n;
// 	    cin>>x>>n;
// 	    string s;
// 	    cin>>s;
// 	    int count=0;
// 	    if (s[0] == '0')
// 	        cout<<"NO"<<endl;
// 	    else
// 	    {
//     	    for (int i=0; i<x; i++)
//     	    {
//     	       // cin>>s[i];
//     	        if (s[i] == '1')
//     	            count++;
//     	    }
//     	   if (count >= n)
//     	    cout<<"YES"<<endl;
//     	   else
//     	    cout<<"NO"<<endl;
// 	    }
	    
// 	}

// }


#include <bits/stdc++.h>

int main() {
  int arr[4] = {1, 5, 4, 9};
//   int n= sizeof(arr) / sizeof(arr[0]);
    int n=4;
  // Sort the range from arr[2] to arr[4]
  std::sort(arr + 2, arr + 5);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}

Points Covered
1.  Significance of selected DBS 
2. Different types of Storage engines available under MySQL
3. Efficiency of MySQL
4. Performance of MySQL 
5. Transactional Properties of MySQL 