/*Problem Statement : 
sort an array of integers using merge sort 


 Solution strategy : 


*/
#include<bits/stdc++.h>
                        
using namespace std;

void merge(int *p, int low, int m , int high)
{
    
}
    
void mergesort(int *p , int low ,int high)
{
    if(high - low >=1)
    {
        int m = (low+high)/2;
        mergesort(p,low,m);
        mergesort(p,m+1,high);
        merge(p , low, m, high);
    }
}

int main ()
{
    int arr[10]= {2,4,6,3,67,7,3,2,2,15};
    int low = 0 ,  high = 9 ;
    mergesort(arr , low, high);

    
return 0;
}