#include<iostream>
#include<vector>

using namespace std ; 
#define SIZE 3

void search(vector<int> &sub , int k)
{
    if(k==SIZE)
    {
        cout<<"{ ";
            for(int i = 0 ; i < sub.size() ; i++)
            cout<<sub[i]<<" ";
        cout<<"}"<<endl;
    }
    else
    {
        search(sub , k+1);
            sub.push_back(k);
        search(sub , k+1);
            sub.pop_back();
    }
}

int main()
{
    vector<int> sub ; 

    search(sub ,0);
}