#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{   
	
	ll t,n;
	cin>>t>>n;
	while(t--){
		for(ll i=1;i<n;i++){
			ll id;
			cout<<"M"<<" "<<i<<" "<<n<<endl;
			cin>>id;
			if(id!=i){
				ll chk;
				cout<<"S"<<" "<<i<<" "<<id<<endl;
				cin>>chk;
			}
		}
		ll chk;
		cout<<"D"<<endl;
		cin>>chk;
		if(chk!=1) break;
	}

    return 0;
}
