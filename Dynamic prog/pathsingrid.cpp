/*Problem Statement : 
given a grid print the maximum sum possible , the only paths allowed in an n * n matrix is going right or going down 


 Solution strategy : 

 calculate val[i][j] = max(sol(i-1,j) , sol(i , j-1)+val[i][j]; 

 this is a recursive solution , can be done iteratively 

 it cant have a greedy approach   --- reason being it maybe that it never reaches the end point and always goes right , in that case it will
 also lose the numbers that maybe below it 

    in this example output should be 67

*/
#include<bits/stdc++.h>
                        
using namespace std;

                        
int main ()
{
 int arr[5][5] = {{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
 int sum[5][5];
 sum[0][0] = arr[0][0];
 for(int i = 1  ;i < 5 ;i++)
 {
    sum[0][i] = arr[0][i]+ sum[0][i-1]; 
    sum[i][0] =  arr[i][0] + sum[i-1][0] ;
 }
 
for(int  i = 1  ; i < 5 ;i++)
{
    for(int j = 1 ; j < 5  ; j++)
    {
        sum[i][j] = max(sum[i-1][j] , sum[i][j-1])+arr[i][j];
    }
}

cout<<sum[4][4] ; 

return 0;
}