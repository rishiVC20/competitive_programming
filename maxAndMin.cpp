#include<bits/stdc++.h>
using namespace std;

int main() {
    int x,y,z;
    cin>>x>>y>>z;
    int min,max;
    if (x>=y && x>=z){
        max = x;
        if (y>=z)
            min = z;
        else 
            min = y;    
    }
    else if (y>=x && y>=z){
        max = y;
        if (x>=z)
            min = z;
        else
            min = x;
    }
    else if (z>=x && z>=y){
        max = z;
        if (x>=y)
            min = y;
        else
            min = x;    
    }
    else if (x == y && y == z ){
        min = x;
        max = x;
    }
    cout<<min<<" "<<max;
   return 0;
}