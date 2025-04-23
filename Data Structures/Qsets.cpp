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


int main()
{
    #ifndef ONLINE_JUDGE
    auto start = high_resolution_clock::now();
    #endif

    FAST
    
    //code
    test
    {
        int arr[4];
        for(int i = 0 ; i  <4 ; i++)
            cin>>arr[i];

        int q = arr[2]-arr[1];
        int count = 0 ;

        for(int j = 0 ; j < 4 ;j++)
            cout<<arr[j]<<" ";
        cout<<endl;
        if(q = arr[0]+arr[1])
            count++;
        if(arr[3]= q + arr[1])
            count++;
        if(arr[4]=arr[3]+q)
            count++;

        cout<<count<<"\n";
    }

    
  
    #ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cerr << "Time: " << duration.count() << " millis" << endl;
    #endif
    return 0 ;
}
