/*Problem Statement : 

find the longest increasing subsequence  ;   next item is larger then previous
    eg in   6   2   5   1   7   4   8   3   
    the lis is  2 5 7 8 


 Solution strategy : 

 maintain a dp array which will contain the count of numbers 
 count = count of number smaller than current + 1 ; 

 time complexity will be O(n^2) at max


*/
#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{

    int arr[8] = {6,2,5,1,7,4,8,3};
    int count[8] ; 
    for(int i = 0 ; i < 8 ; i++)
    {
        count[i] = 1 ;
        for(int j = 0 ; j < i ; j++)
        {
            if(arr[j]<arr[i])
                count[i] = max(count[j]+1 , count[i]);
        }
    }

    for(int i = 0  ; i < 8 ;i++)
    {
        cout<<count[i]<<endl ; //acc to every index the subsequence will change
    }

    cout<<*max_element(count, count+8 ); // this will print the longest increasing subsequence in the complete array
    
return 0;
}