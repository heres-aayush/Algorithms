/* map data structure -  
    key - value pair 
    key - any data type 
    balanced binary tree hence O(log n )
    keys are case sensitive 
    
        */
#include<bits/stdc++.h>
                        
using namespace std;
                        
int main (void)
{
    map<string,int > ms;
    ms["monkey"]= 1;
    ms["banana"] =4;
    cout<<ms["banana"]<<endl; //outputs 4
    cout<<ms["hello"]++<<endl; // 0 
    cout<<ms["hello"]<<endl; // 1

    cout<<ms["Banana"]<<endl;

    //check if exists  ms.count

    cout<<ms.count("banana")<<endl; 

    //printing all the key value pairs  - 
    for(auto ele:ms)
        cout<<ele.first<< "  "<<ele.second <<endl; // lexicographical order (ascii)


return 0;
}