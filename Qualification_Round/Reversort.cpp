//Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

//Solution:

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
	
	ll t,ii=0;
	cin>>t;

	while(t--){
		ll n;
		cin>>n;

		ll a[n+1];
		for(ll i=1;i<=n;i++) cin>>a[i];

		ll ans=0;
		for(ll i=1;i<n;i++){
			ll id;
			for(ll j=i;j<=n;j++){
				if(a[j]==i){
					id=j;
					break;
				}
			}
			ans+=(id-i+1);
			reverse(a+i,a+id+1);
			//for(ll j=1;j<=n;j++) cout<<a[j]<<" ";cout<<endl;
		}
		cout<<"Case #"<<++ii<<": "<<ans<<endl;
	}

	return 0;
}
