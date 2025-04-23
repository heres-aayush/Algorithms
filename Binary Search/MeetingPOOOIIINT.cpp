//Problem Statement : 
    //given a line , n people standing , given coordinates xi , and their max speeds vi;
    // find the min time to meet at a specific distance


// Solution strategy : 
    // for all person calculate the max and min distance (xi + vi.t) and (xi - vi.t)


#include<bits/stdc++.h>
#include<vector>

                        
using namespace std;
#define EPS 10e-4

int good(vector <int> &xi , vector<int>&vi , float t )
{
    int li , ri ;
    int maxli = 0 , minri = 0 ;

    for(int i  = 0 ; i < xi.size() ; i++)
    {
        li = xi[i] - vi[i]*t;
        ri = xi[i] + vi[i]*t;

        maxli = max(li,maxli);
        minri = min(ri,minri);
    }

    return maxli<=minri;
}


                        
int solve (vector<int> xi, vector<int> vi , int n )
{
    float l = 0 ; // intial timing
    float r = 999999; // considering they may meet in these many seconds

    while(r-l>EPS)
    {
        float  m = (l+r)/2;
        if(good(xi , vi , m ))
            r = m ; 
        else
            l = m ;
    }
    return r;
}


int main ()
{   
    int n ;
    cin>>n;
    vector<int> xi(n);  
    for(int &ele : xi)
    {
        cin>>ele;
    }

    vector<int> vi(n);
    for(int &ele2 : vi)
    {
        cin>>ele2;
    }

    float time = solve (xi , vi, n);
    cout<<time<<endl;


    return 0;
}