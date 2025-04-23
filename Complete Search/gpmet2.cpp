/*Problem Statement : 

generating permutation of n numbers from 0 to n-1

 Solution strategy : 

using the next_permutation STL 
prints in inreasing order eg: - 
{ 012 }
{ 021 }
{ 102 }
{ 120 }
{ 201 }
{ 210 }
*/
#include<bits/stdc++.h>
        
#define n 3
using namespace std;
                        
int main ()
{
    vector<int> permute ;
    for(int i = 0 ; i < n ;i++)
        permute.push_back(i);
    do
    {   
        /* code */
        cout<<"{ ";
        for(int i = 0 ; i < permute.size() ; i++)
        {
            cout<<permute[i];
        }
        cout<<" }\n";
    } while (next_permutation(permute.begin() , permute.end()));
    
    
return 0;
}