/*Problem Statement : 

Given a target , here =8  , find whether or not a subarray exist with sum=target

 Solution strategy : 
	1. We move right , if the sum is lesser than target
    2. We move left , if the adding another element from right exceeds the sum .

    Hardcoded to 8 and exceptions are not handled (i.e not found).  ---> can do it using flag 

*/
#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{
    int arr[8] = {1,3,2,5,1,1,2,3} ; 
    int target = 8 ;  
    int l = 0 , r = 0  ; 
    int sum = arr[0] ; 
    // for(int i = 1; i< 8 ;i++) you will have to take care of decrementing i if inc l ;
    while(r<8)
    {
        if(sum==target )
            break ; 
        else
        {
            if(sum+arr[r+1] <= target)
            {
                sum+=arr[++r];
            }
            else
            {
                sum-=arr[l++];
            }
        }
    }

    for(int i = l ; i <= r ; i++)
    {
        cout<<arr[i] <<" "; 
    }

    cout<<'\n';
return 0;
}