// we are given Width and height of a rectangle , we need to find minimum (square of size) x for which it can fit n rectangles 
// input width , height and n

// solution includes finding the minimum good number 

#include<bits/stdc++.h>
using namespace std;

int good(int x, int w ,int h , int n  )
{
    return (x/h)*(x/w) >= n;
}


int solve (int w , int h , int n )
{
    int l = 0 ;// lowest value which cant be x
    int r = 99999;// say the max size of sq . based on inputs , can be max(w,h)*n;

    while(l+1<r)
    {
        
        int m = (l+r)/2;
        if(good(m,w,h,n))
            r= m ; // good number shift right 
        else
            l=m;
    }

    return r;

}

int main()
{
    int w, h , n ;
    cin>>w>>h>>n;
    
    int q = solve (w,h,n);
    cout<<q;
    

    return 0;
}   
