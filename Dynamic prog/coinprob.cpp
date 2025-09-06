/*Problem Statement : 

given a coin set ex - {1,3,4} we need to find the min number of coins required 

 Solution strategy : 

    if x< 0  infinity
    if x = 0 ;  0 
    if x >0 , min (solve (x-c) + 1) ;  since to get the previous state and then add one more coin which will be 1,3,4 


* boolean array
int results ; 

*/
#include<bits/stdc++.h>
                        
using namespace std;



int solve(int x , int ans[] , bool res[]) 
{
    int coins[] = {1,3,4};
    int best = 9999; 
    if(x < 0 )
        return 9999; 
    if(x==0)
        return 0 ; 
    if(res[x] == true)
    {
        return ans[x]; 
    }
    if(x>0)
    {
        for(int c: {1,3,4})
        {
            best = min(best , solve (x-c , ans , res) + 1);
        }
      
    }
      ans[x] = best ; 
        res[x] = true;
    return best  ;
}

int main()
{
    int amount = 10; 
    int ans[amount+1];
    bool ex[amount+1];
    cout<<solve(amount , ans, ex);
}