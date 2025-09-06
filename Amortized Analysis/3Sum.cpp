/*Problem Statement : 

find whether 3 elements in an array sum upto the target ; 

 Solution strategy : 


*/
#include<bits/stdc++.h>
                        
using namespace std;
                    
int binarySearch(int* arr, int key , int left ,int right)
{
    int mid ; 
    while(left <= right)
    {
        mid = (left+right)/2 ; 
        if(key > arr[mid ])
            left = mid+1 ; 
        else if (key < arr[mid] )
            right = mid -1; 
        else if(key == arr[mid])
            return mid ; 
    }
    return 0 ; 
}
void solve(int *arr  ,int target)
{
    int n = 8 ;  
    int left = 0 ; 
    int right = n-1 ; 
    int found =0 ;
    sort(arr,arr+n);
    while(left < right )
    {
        if(arr[left] + arr[right ] < target )
        {
            int q ; 
            int key = target - arr[left] - arr[right] ; 
            if(key >= left )
             q = binarySearch(arr, key , left+1, right ) ; 
            if(key < left )
             q = binarySearch(arr, key , 0 , left ) ; 

             if(q)
                {
                    cout<<"YEs"<<"\n" ;
                    found =1 ; 
                    break ; 
                }
            if(!q)
                left++;
        }
        else 
            right--;
    }
    if(found == 0 )
        cout<<"no\n";
}
int main ()
{
    int arr[8] = {1,1,2,2,7,46,1,3}; 
    int target = 56; 
    solve (arr, target); 
return 0;
}