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


ll catchY(ll x , ll y , ll yend , ll k , ll  xend)
{
    ll num = x;
    ll count = 0 ;
   while(x<xend)
   {
        if(num>=y && num<=yend)
        {
            count++;
            num = num*k;
        }
        else if(num<y)
        {
            num = num*k;
        }
        else if(num>yend)
        {
            num = x++;
        }
   }
   return count; 

}

int main()
{
    FAST
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    //code
    test
    {
        ll k , l1,r1,l2,r2;
        cin>>k>>l1>>r1>>l2>>r2; 
        
        ll count ;
       
            count = catchY(l1 , l2, r2 ,k ,r1);
        
        cout<<count<<"\n";
    }

    
  
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "Time: " << duration.count() / 1000.0 << " millis" << endl;
    #endif
    return 0 ;
}
