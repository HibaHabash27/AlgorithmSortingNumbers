#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex)     
{
    int i, j, k;
    const int rightArraySize = rightIndex - midIndex;
    const int leftArraySize = midIndex - leftIndex + 1;                                
    int L[leftArraySize], R[rightArraySize];
    
    for (i = 0; i < leftArraySize; i++){
        L[i] = array[leftIndex + i];
    }
    for (j = 0; j < rightArraySize; j++){
        R[j] = array[midIndex + 1 + j];
    }

    i=0; 
    j=0;
    k=leftIndex;

    while (j < rightArraySize && i < leftArraySize  )
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftArraySize)
    {
        array[k] = L[i];
        i++; k++;
    }

    while (j < rightArraySize)
    {
        array[k] = R[j];
        j++;k++;
    }
}


void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) //anchor
    {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        
        mergeSort(array, midIndex +1 , rightIndex);
        
        mergeSort(array, leftIndex, midIndex);
        

        merge(array, leftIndex, midIndex, rightIndex);
    }
}




int main()
{

    int arraySize  ;
    cin>>arraySize;
    int A [arraySize];
    for(int i = 0 ; i <arraySize ; i++){
        cin>>A[i];
    }


     mergeSort(A, 0, arraySize-1);

    // code to print the array
   cout<<"[";
   for (int i=0 ; i<arraySize ; i++) {
    cout<<A[i];
    if(i<(arraySize-1))cout<<",";
   }
    cout<<"]";
        
    return 0;

    }

