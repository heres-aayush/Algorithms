/*Problem Statement : 

Given a target x report whether there exist two numbers in array with sum = x 
report if doesn’t exist

 Solution strategy : 

 Sort the array - O(nlogn)
 Move the pointers  - O(n)  
Overall complexity  = O(n logn )


 put two pointer left and right , left - 0 ;  right = n-1 ; 

 if left + right > target => decrement right 
 if < target => increment left ; 

  while(left<right)do 
  repeat line 11, 12 

  if (fopund) break 
  else not found ;

*/
#include<bits/stdc++.h>
                        
using namespace std;
    
void solve(int *arr , int target )
{
    int n = 8 ;
    sort(arr,arr+n); 
    int left  = 0 ; 
    int right = n-1 ; // n=8 currently hardcoded ; 
    int found  = 0 ; // acts as a flag
    while(left<right)
    {
        if(arr[left] + arr[right] == target )
            {
                found = 1 ; 
                break ; 
            }
        else if(arr[left]+arr[right] > target )
        {
            right-- ; 
        }
        else if(arr[left]+arr[right] < target)
            left++ ; 
    }
    if(found)
        cout<<"Yes\n" ; 
    else
        cout<<"No\n" ; 
}
int main ()
{
    int arr[8] = {1,1,1,1,7,1,1,1}; 
    int target = 8 ; 
    solve (arr, target); 
    
return 0;
}