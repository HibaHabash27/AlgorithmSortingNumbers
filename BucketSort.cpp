#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define BUCKET_SIZE 10

class Node  
{  
    public: 
    int data;  
    Node *next;  
};  


void insertNode(Node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    Node* new_node = new Node(); 
    Node *p1 , *p2 ;
    p1 = NULL; 
    p2 = NULL ;
  
    /* 2. put in the data */
    new_node->data = new_data;  
    /*int a = ((*head_ref)->data);
    cout<<a<<endl;*/
    if ((*head_ref) == NULL){
        new_node->next = (*head_ref);  
        (*head_ref) = new_node; 
    }
    else if (((*head_ref)->data) > new_data)
    {
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;
    }
    else
    {
        p1= (*head_ref);
        p2 = p1 -> next;
        while (p2 != NULL){
            if (p2->data > new_data)
            {
                p1->next = new_node;
                new_node->next= p2;
                return;
            }
            p1 = p2;
            p2 = p2->next;
        }
        p1->next=new_node;
        
        
    }
}  


int findMax (int * A,int n){
    int max = A[0];
    for (int i =1 ; i<n ; i++)
        if (A[i] > max )
            max= A[i];
    return max;
}



int main() {
    int n , i,j ;
    cin>>n;
    int A [n];
    for(i = 0 ; i <n ; i++){
        cin>>A[i];
    }
    
    Node * head = NULL;
    int max = findMax(A,n); 
   
    //total number of elements n
    
    Node * bucket[BUCKET_SIZE] ;
    for (i=0; i<BUCKET_SIZE; i++) bucket[i] = NULL;
    int div = ceil((max+1)/float(BUCKET_SIZE));
    
    for (i=0 ; i< n ; i++){
       j = floor(A[i]/(div)); 
       insertNode(&bucket[j], A[i]); 
    
        
    }
    
    
    // Code to check if the buckets are correct 
    /*for (i =0 ; i< BUCKET_SIZE ; i++){
       cout << " bucket number " <<  i << "= ";
        if (bucket[i]!= NULL){
            head = bucket[i];
            while (head != NULL){
                cout<< head->data<<" " ;
                head = head -> next;
            }
        }cout<<endl;
    }*/
    
    int z = 0;
    for (i = 0 ; i < BUCKET_SIZE ; i++){
        if (bucket[i]!= NULL){
            head= bucket[i];
            while (head != NULL){
                A[z]=head->data;
                z++;
                head = head -> next;
            }
            
            
        }
    }
    // code to print the array
   cout<<"[";
   for (i=0 ; i<n ; i++) {
    cout<<A[i];
    if(i<(n-1))cout<<",";
   }
    cout<<"]";
    
}
