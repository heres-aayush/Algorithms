#include<iostream>
#include <cstdlib>
#include<vector>

#define SIZE 3
using namespace std;


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

int main() {
    // Open Windows Clock App
    system("start ms-clock:");

    // Simulate a wait or let user start stopwatch manually
    system("timeout /t 5");

    // Your program logic here...
    vector<int> sub ; 

    search(sub ,0);
    
    // After program ends, close the Clock app
    system("taskkill /IM WinClock.exe /F");
    
    return 0;
}
