//mmultiset is same like sets but can hold multiple instances of the same element
// it is also ordered like sets

#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{
    multiset<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);
    cout<<s.count(2)<<endl;

   

    s.erase(s.find(2));
    
    for(int ele: s)
    {
        cout<<ele<<" ";
    }

    
return 0;
}
// output - 2
//          2 2 3 4 