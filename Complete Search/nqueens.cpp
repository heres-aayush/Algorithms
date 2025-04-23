/*Problem Statement : 

how many solutions exist such that in an n*n board , no two queens attack each other

 Solution strategy : 

 backtracking 
 marking cols, daig1 and diag2 as 1 then after search marking it back as 0


*/
#include<bits/stdc++.h>
                        
using namespace std;

int solutionCount = 0 ;
int n = 8; // size of n*n chess board
void search (int y , int col[] , int diag1[] , int diag2[] )
{
    if(y==n)
    {
        solutionCount++;
        return ;
    }
    for(int x= 0 ; x< n ; x++)
    {
        if(col[x]||diag1[x+y]||diag2[x-y+n-1])
            continue;
        col[x]=diag1[x+y]=diag2[x-y+n-1]=1;
        search(y+1,col,diag1,diag2); 
        col[x]=diag1[x+y]=diag2[x-y+n-1]=0;
    }
}
                        
int main ()
{

    int col[n] = {0}, diag1[2 * n - 1] = {0}, diag2[2 * n - 1] = {0}; // initialize arrays
    search(0, col,diag1 , diag2);

    cout<<solutionCount;

return 0;
}