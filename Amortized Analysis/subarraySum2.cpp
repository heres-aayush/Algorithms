/*Problem Statement : 

    subarray sum second approach ...

 Solution strategy : 

 not handling not found 


*/
#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{
    int arr[8] = {1,3,2,5,1,1,2,3};
    int target = 9; 
    int l = 0 ; 
    int r  = 0  ;
    int sum = arr[0]; 
    while(r<8) 
    {
        if(sum == target)
            break ; 
        if(sum < target)
             sum+=arr[++r];
        if(sum > target)
        {
            sum-=arr[l++];
        } 
    }

    for(int i = l ; i <=r ;i++)
    {
        cout<<arr[i]<<" "; ; 
    }
    cout<<"\n";

return 0;
}