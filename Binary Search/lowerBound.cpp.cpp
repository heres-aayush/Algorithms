/* वक्रतुण्ड महाकाय सूर्यकोटि समप्रभ । निर्विघ्नं कुरु मे देव सर्वकार्येषु सर्वदा ॥ */
#include<bits/stdc++.h> 
using namespace std;
using namespace std::chrono;

#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
#define test ll t ; cin>>t; while(t--)

typedef long long ll;
typedef vector<int> vi;
typedef list<ll> li;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll, ll> pl;

int solve (vi v , int  x)
{   
    int l = -1 ; 
    int r = v.size();

    while(r>l+1)
    {
        int m = (l+r)/2;
 
        if(v[m]>x)
        {
            r = m;
        }
        else
            l=m;
    }
    return l;
}

int main()
{
    FAST
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    //code

    vi v({2,5,7,8,10,11,12,15,18});
    int q = solve(v,3);
    // cout<<v[1]<<endl;
    cout<<q<<endl;
        
  
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "Time: " << duration.count() / 1000.0 << " millis" << endl;
    #endif
    return 0 ;
}
