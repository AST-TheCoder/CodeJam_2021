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

	vector<ll> x;
	for(ll i=1;i<=1000;i++){
		ll c=i;
		for(ll j=i+1;c<=10000000;j++){
			ll p=log10(j)+1;
			ll d=1;
			while(p--) d*=10;
			c*=d;
			c+=j;
			x.pb(c);
			//if(c==901) cout<<i<<" "<<j<<" "<<d<<endl;
		}
	}
	sort(all(x));
	//cout<<x.size()<<endl;for(ll i=0;i<x.size();i++) cout<<x[i]<<" ";cout<<endl;

	ll t,ii=0;
	cin>>t;
	read:
	while(t--){
		ll y;
		cin>>y;
		for(ll i=0;i<x.size();i++){
			if(x[i]>y){
				cout<<"Case #"<<++ii<<": "<<x[i]<<endl;
				goto read;
			}
		}
	}

    return 0;
}
