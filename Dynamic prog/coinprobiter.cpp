/*Problem Statement : 

given a coin set ex - {1,3,4} we need to find the min number of coins required 

Sol strat : 
value[x] = min (value[x] , value[x-c]+1)


//constructing a solution 
---> store the first coin used and iteratively / recursively search for the solution for previous item that is n -  first 

*/
#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{
    int coins[] = {1,3,4};
    int amount = 10;
    int val[amount+1] ;
    val[0]=0;
    int first[amount + 1] ; 
    for(int i= 1 ;i <= amount;i++)
    {
        val[i]= 9999;
        for(int c : {1,3,4})
        {
            if((i-c)>=0 && val[i-c]+1 < val[i]) 
            {
                val[i] = val[i-c]+1;
                first[i] = c ; 
            }
           
        }
    }

    cout<<val[amount]<<endl;
    while(amount>0)
    {
        cout<<first[amount]<<" ";
        amount -= first[amount];
    }
return 0;
}