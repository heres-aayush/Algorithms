/*Problem Statement : 


 Solution strategy : 


*/
#include<bits/stdc++.h>
                        
using namespace std;

static int y = 15 ;

class hello{
    public:
    int x ; 
    public: 
    void show ()
    {
        cout<<this->x<<endl;
    }
};

// int hello :: x = 10;

int main ()
{
    
    cout<<y<<"\n";
  hello h1 ;
  cout<<h1.x<<endl;
  h1.show();  
return 0;
}