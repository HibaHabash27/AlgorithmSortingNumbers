#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Hiba Ibrahim Mohammad Habash 11821610
    int n , i ;
    cin>>n;
    int A [n];
    for(i = 0 ; i <n ; i++){
        cin>>A[i];
    }
    
    int temp , H; 
    // code to insertion sort 
    for ( i =1 ; i<n ;i++ ){
        temp = A[i];
        H= i-1;
        while (H>=0){
            if (A[H]<temp)break;
            A[H+1]=A[H];
            H--;
        }
        A[H+1]=temp;
    }
    
    // code to print the array
   cout<<"[";
   for (i=0 ; i<n ; i++) {
    cout<<A[i];
    if(i<(n-1))cout<<",";
   }
    cout<<"]";
    

    
    
   
    
    return 0;
}
