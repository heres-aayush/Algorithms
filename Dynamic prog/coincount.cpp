/*Problem Statement : 

given coins 1 3 4 count the possible number of solutions for a particular amount    

 Solution strategy : 

 using recursion (can also use memoization) making dp 
    sol(x) = sol(x-1)+sol(x-3)+sol(x-4)
    can store sol(x) to avoid calc again 
    if(x<0) return 0 
    else if (x==0 ) return 1

    i have used void method here , better to use int and return 

*/
#include<bits/stdc++.h>
                        
using namespace std;
int solve(int x , bool pres[] , int sol[])
{
    if(x<0)
        return 0 ; 
    else if(x==0)
        return 1 ; 
    else
    {
        if(pres[x] == true)
            return sol[x] ; 
        else
        {
            sol[x] = solve(x-1, pres, sol)+solve(x-3, pres, sol)+solve(x-4 , pres, sol); 
            pres[x] =  true ; 
        }
    }

    return sol[x];
}
                        
int main ()
{
 int coins[] = {1,3,4};
 int amount = 4 ;
 int sol[amount+1] ; 
 bool present[amount+1] = {false};
 cout<<solve(amount , present , sol );   
return 0;
}