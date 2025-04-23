/*Problem Statement : 

generating a permutaion of n numbers from 0 to n-1

 Solution strategy : 

 recursive solution ...by choosing a choice setting its value to true and then opting that oiut in the next call

*/
#include<bits/stdc++.h>
                        
using namespace std;

#define n 4

vector <int> permutations;

void search(bool choice[])
{   
    //if permutations size = n where permutations is a vector
    if(permutations.size() == n )
    {
        cout<<"{ ";
        for(int i = 0 ; i < permutations.size() ; i++)
        {
            cout<<permutations[i];
        }
        cout<<" }\n";
    }

    for(int  i = 0 ;  i < n ; i++)
    {
        if(choice[i])
        {
            continue ;
        }
        choice[i] = true;
        permutations.push_back(i);
        search(choice);
        permutations.pop_back();
        choice[i]  = false;
    }
}

int main ()
{
    bool choice[n];
    search(choice);
return 0;
}