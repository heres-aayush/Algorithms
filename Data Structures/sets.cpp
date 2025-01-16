// The set data structure  stores unique elements in specific order ... also has unordered set which is more efficient but is not sorted /
// operations include -  count() , insert() ,  remove() , find().
// set is a balanced binary seach  hence O(logn);
//unordered_set workd in O(1)


#include<bits/stdc++.h>
                        
using namespace std;
                        
int main ()
{
    set <int > s;
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(2);
    //iterating through the set . cannot be accessed like arrays
    for (int ele: s)
        cout<<ele<<"\n";

    cout<<s.count(4)<<"\n"; // counts the element (will always return 0 or 1)

    s.erase(3);//erases the element
    if(s.find(2)!=s.end()) // an iterator which searches for the element 
        cout<<"Element found"<<"\n";
    else
        cout<<"Element not found"<<"\n"; //return end if not found


return 0;
}