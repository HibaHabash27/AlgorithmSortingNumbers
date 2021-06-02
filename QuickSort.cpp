//Hiba Ibrahim Habash 11821610
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findPivotLocation(int array[], int Begin, int End) {
    int temp;
    int i = Begin;
    int j = End;
    int pivotLocation = i;
    while (true)
    {
        while (array[pivotLocation] <= array[j] && pivotLocation != j)
        {
            j--;
        }
        if (pivotLocation == j)
            break;
        else if (array[pivotLocation] > array[j])
        {
            temp= array[j];
            array[j]=array[pivotLocation];  //swap array[j] and array[pivotLocation] if array[pivotLocation] > array[j]
            array[pivotLocation]=temp;
            pivotLocation = j;
        }

        while (array[pivotLocation] >= array[i] && pivotLocation != i)
        {
            i++;
        }
        if (pivotLocation == i)
            break;
        else if (array[pivotLocation] < array[i])
        {
            temp = array[i];
            array[i]= array[pivotLocation]; 
            array[pivotLocation]=temp;//swap array[beginIndex] and array[pivotLocation] 
            pivotLocation = i;
        }
    }
    return pivotLocation;
}


void quickSort(int array[], int Begin, int End)
{

    if (Begin < End) {
        int pivotLocation = findPivotLocation(array, Begin, End);
        quickSort(array, pivotLocation + 1, End);
        quickSort(array, Begin, pivotLocation - 1);
    }

}

int main()
{
    // code to read the array
    int n , i ;
    cin>>n;
    int A [n];
    for(i = 0 ; i <n ; i++){
        cin>>A[i];
    }
    
    
    
    quickSort(A, 0, n - 1);
    
      // code to print the array
   cout<<"[";
   for (i=0 ; i<n ; i++) {
    cout<<A[i];
    if(i<(n-1))cout<<",";
   }
    cout<<"]";

    return 0;
}