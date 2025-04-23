/*Problem Statement : 
    subsets based on bit representation of integers

 Solution strategy : 
    Bit manipulation 
    1<<i is
    "Shift the number 1 to the left by i positions in binary."
    So:
    1 << 0 = 1 → binary: 0001
    1 << 1 = 2 → binary: 0010
    1 << 2 = 4 → binary: 0100
    1 << 3 = 8 → binary: 1000
    and so on...
*/
#include<bits/stdc++.h>
                        
using namespace std;

void solve(int n )
{
    for(int b = 0 ; b < (1<<n); b++) // 1<<n makes 8 for n=3 , shift 1 three places to the left making it 8
    {
        vector<int> subsets;
        for(int i = 0 ; i < n ; i++)
        {
            if( b & (1<<i)) //bitwise and operator
                subsets.push_back(i);
        }
        for(int j = 0 ; j < subsets.size()  ; j++)
        {
            cout<<subsets[j]<<" ";
        }
        cout<<endl;
    }
}
                        
int main ()
{
    solve (3); // will generate subsets of 0,1,2
    return 0;
}